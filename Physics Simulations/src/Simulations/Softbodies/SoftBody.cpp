#include "SoftBody.h"

void SBS::SoftBody::Update(float deltaTime, WorldData* worldData)
{
	for (int i = 0; i < m_pointMasses.size(); ++i)
	{
		PointMass* pMass = m_pointMasses[i];

		// Reset forces
		pMass->force = glm::vec2(0.f, 0.f);

		// Accumulate forces
		glm::vec2 mg = worldData->pointmassData.mass * worldData->physicsData.gravity;
		pMass->force += mg;

		// Collision
		for (int j = i; j < m_pointMasses.size(); ++j)
		{
			if (i == j) continue;

			PointMass* pMass2 = m_pointMasses[j];

			if (IsColliding(pMass, pMass2, worldData->physicsData))
			{
				ResolveCollision(pMass, pMass2, worldData->physicsData);
			}
		}
	}

	// Accumulate spring forces
	for (Spring* const spring : m_springs)
	{
		float stiffness = worldData->springData.stiffness;
		float dampFactor = worldData->springData.dampFactor;
		glm::vec2 springForce = spring->CalcSpringLinearForceP21(stiffness, dampFactor);
		spring->p1->force -= springForce;
		spring->p2->force += springForce;
	}

	// Integrate momentum
	for (PointMass* const pMass: m_pointMasses)
	{
		pMass->vel += (pMass->force / pMass->mass) * deltaTime;
		pMass->pos += pMass->vel * deltaTime;

		// Constrain to the screen/world boundaries
		Constrain(pMass, worldData->boundaryData, worldData->physicsData);
	}
}

void SBS::SoftBody::Render(olc::PixelGameEngine* pge)
{
	for (Spring* const spring : m_springs)
	{
		glm::vec2 p1(spring->p1->pos);
		glm::vec2 p2(spring->p2->pos);
		pge->DrawLine(p1.x, p1.y, p2.x, p2.y, olc::WHITE);
	}
	for (PointMass* const pMass : m_pointMasses)
	{
		pge->FillCircle(pMass->pos.x, pMass->pos.y, pMass->radius, pMass->color);
	}
}

void SBS::SoftBody::Constrain(PointMass* pMass, const BoundaryData& boundary, const PhysicsData& physics)
{
	float xMin = boundary.min.x + pMass->radius;
	float xMax = boundary.max.x - pMass->radius;
	float yMin = boundary.min.y + pMass->radius;
	float yMax = boundary.max.y - pMass->radius;

	if (pMass->pos.x < xMin)
	{
		pMass->pos.x = xMin;
		pMass->vel.x *= -physics.coefRestitution;
	}
	if (pMass->pos.x >= xMax)
	{
		pMass->pos.x = xMax;
		pMass->vel.x *= -physics.coefRestitution;
	}
	if (pMass->pos.y <= yMin)
	{
		pMass->pos.y = yMin;
		pMass->vel.y *= -physics.coefRestitution;
	}
	if (pMass->pos.y >= yMax)
	{
		pMass->pos.y = yMax;
		pMass->vel.y *= -physics.coefRestitution;
	}
}

bool SBS::SoftBody::IsColliding(PointMass* p1, PointMass* p2, const PhysicsData& physics)
{
	return glm::distance(p1->pos, p2->pos) < (p1->radius + p2->radius);
}

void SBS::SoftBody::ResolveCollision(PointMass* p1, PointMass* p2, const PhysicsData& physics)
{
	glm::vec2 p12 = glm::normalize(p2->pos - p1->pos);

	float sumRadius = p1->radius + p2->radius;
	float distance = glm::distance(p1->pos, p2->pos);
	float overlap = sumRadius - distance;

	// Each pointMass will be displaced 
	// backwards by half the overlap
	glm::vec2 displacement = p12 * overlap * 0.5f;
	p1->pos -= displacement;
	p2->pos += displacement;

	glm::vec2 v1 = p1->vel;
	glm::vec2 v2 = p2->vel;
	glm::vec2 v12 = v2 - v1;

	float sqrRestitution = physics.coefRestitution * physics.coefRestitution;

	p1->vel = 2 * p2->mass / (p1->mass + p2->mass) *
			  glm::dot(v12, p12) * p12 * sqrRestitution;

	p2->vel = 2 * p1->mass / (p1->mass + p2->mass) *
			  glm::dot(v12, p12) * p12 * sqrRestitution;
}

