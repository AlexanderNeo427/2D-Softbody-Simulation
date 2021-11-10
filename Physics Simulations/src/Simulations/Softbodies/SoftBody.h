#ifndef SOFT_BODY
#define SOFT_BODY

#include "Spring.h"

namespace SBS
{
	class SoftBody
	{
	public:
		SoftBody(std::vector<PointMass*> pointMasses, 
				 std::vector<Spring*>	 springs)
			:
			m_pointMasses(pointMasses),
			m_springs(springs)
		{}

		void Update(float deltaTime)
		{
			for (int i = 0; i < m_pointMasses.size(); ++i)
			{
				PointMass* pMass = m_pointMasses[i];

				// Reset forces
				pMass->force = glm::vec2(0.f, 0.f);

				// Accumulate forces
				// pMass->AddForce();

				// Collision
				for (int j = i; j < m_pointMasses.size(); ++j)
				{
					if (i == j) continue;

					PointMass* pMass2 = m_pointMasses[i];

				}
			}

			// Accumulate spring forces
			for (Spring* const spring : m_springs)
			{
				// TODO
				// glm::vec2 springForce = spring->CalcSpringLinearForceP21();
				// spring->p1->force -= springForce;
				// spring->p2->force += springForce;
			}

			// Integrate momentum
			for (PointMass* const pMass: m_pointMasses)
			{
				pMass->vel += (pMass->force / pMass->mass) * deltaTime;
				pMass->pos += pMass->vel * deltaTime;
			}
		}

		void Render(olc::PixelGameEngine* pge) const
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
	private:
		std::vector<PointMass*> m_pointMasses;
		std::vector<Spring*>	m_springs;
	};
}

#endif