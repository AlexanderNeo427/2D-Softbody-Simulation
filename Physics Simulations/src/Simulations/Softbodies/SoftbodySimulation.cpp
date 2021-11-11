#include "SoftbodySimulation.h"

SBS::SoftbodySimulation::SoftbodySimulation(olc::PixelGameEngine* pge)
	:
	SimulationBase(pge),
	m_worldData(nullptr)
{}

void SBS::SoftbodySimulation::Init()
{
	InitializeWorldData();

	float startX = m_screenWidth * 0.4f;
	float startY = m_screenHeight * 0.2f;
	glm::vec2 pos(startX, startY);

	float restLength = m_screenWidth < m_screenHeight ?
					  (m_screenWidth / REST_LENGTH_RATIO) : 
					  (m_screenHeight / REST_LENGTH_RATIO);

	SoftbodyBuilder softbodyBuilder(m_worldData);
	glm::ivec2 numPoints(7, 11);
	m_softBody = softbodyBuilder.GenerateCube(pos, m_worldData->pointmassData,
											  m_worldData->springData, 
											  glm::ivec2(7, 11), restLength);
}

void SBS::SoftbodySimulation::Update(float deltaTime)
{
	// Input for sliders
	//if (m_floatSliders.size() > 0)
	//{
	//	if (m_pge->GetKey(olc::DOWN).bPressed)
	//	{
	//		m_index = (m_index + 1) % m_floatSliders.size();
	//	}
	//	else if (m_pge->GetKey(olc::UP).bPressed)
	//	{
	//		--m_index;
	//
	//		if (m_index < 0)
	//			m_index = m_floatSliders.size() - 1;
	//	}
	//	else if (m_pge->GetKey(olc::RIGHT).bHeld)
	//	{
	//		float currValue = *(m_floatSliders[m_index]->value);
	//		currValue += deltaTime;
	//		m_floatSliders[m_index]->value = &currValue;
	//	}
	//	else if (m_pge->GetKey(olc::LEFT).bHeld)
	//	{
	//		float currValue = *(m_floatSliders[m_index]->value);
	//		currValue -= deltaTime;
	//		m_floatSliders[m_index]->value = &currValue;
	//	}
	//}

	m_softBody->Update(deltaTime, m_worldData);
}

void SBS::SoftbodySimulation::Render()
{
	m_pge->Clear(olc::BLACK);

	m_softBody->Render(m_pge);

	// std::string value = std::to_string(*(m_floatSliders[m_index]->value));
	// m_pge->DrawString(8, 15, m_floatSliders[m_index]->name + " " + value, olc::WHITE, 2);
}

void SBS::SoftbodySimulation::Exit()
{
	if (m_softBody != nullptr)
	{
		delete m_softBody;
		m_softBody = nullptr;
	}
}

void SBS::SoftbodySimulation::InitializeWorldData()
{
	BoundaryData boundaryData;
	boundaryData.min = glm::vec2(0.f, 0.f);
	boundaryData.max = glm::vec2(m_screenWidth, m_screenHeight);

	PhysicsData physicsData;
	physicsData.gravity			= glm::vec2(0.f, 120.f);
	physicsData.coefFriction	= 0.2f;
	physicsData.coefRestitution = 0.69f;

	SpringData springData;
	springData.stiffness  = 690.f;
	springData.dampFactor = 0.69f;

	PointMassData pointmassData;
	pointmassData.mass	 = 1.f;
	pointmassData.radius = 6.f;

	m_worldData = new WorldData();
	m_worldData->boundaryData  = boundaryData;
	m_worldData->physicsData   = physicsData;
	m_worldData->springData	   = springData;
	m_worldData->pointmassData = pointmassData;
}

void SBS::SoftbodySimulation::UpdateWorldData()
{

}
