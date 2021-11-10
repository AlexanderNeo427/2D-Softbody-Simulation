#include "SoftbodySimulation.h"

SBS::SoftbodySimulation::SoftbodySimulation(olc::PixelGameEngine* pge)
	:
	SimulationBase(pge),
	m_worldData(nullptr),
	m_updateData(nullptr)
{}

SBS::SoftbodySimulation::~SoftbodySimulation()
{
	for (int i = 0; i < m_softBodies.size(); ++i)
	{
		if (m_softBodies[i] != nullptr)
		{
			delete m_softBodies[i];
			m_softBodies[i] = nullptr;
		}
	}
}

void SBS::SoftbodySimulation::Init()
{
	// m_updateData = new UpdateData(m_pge);
	// 
	// m_worldData->gravity  = glm::vec2(0.f, GRAVITY);
	// m_worldData->worldMin = glm::vec2(0.f, 0.f);
	// m_worldData->worldMax = glm::vec2(m_screenWidth, m_screenHeight);

	float startX = m_screenWidth * 0.25f;
	float startY = m_screenHeight * 0.1f;
	glm::vec2 pos(startX, startY);

	float restLength = m_screenWidth < m_screenHeight ?
					  (m_screenWidth / REST_LENGTH_RATIO): 
					  (m_screenHeight / REST_LENGTH_RATIO);


}

void SBS::SoftbodySimulation::Update(float deltaTime)
{
	for (SoftBody* const softbody : m_softBodies)
	{
		softbody->Update(deltaTime);
	}
}

void SBS::SoftbodySimulation::Render()
{
	for (SoftBody* const softbody : m_softBodies)
	{
		softbody->Render(m_pge);
	}
}

void SBS::SoftbodySimulation::Exit() {}
