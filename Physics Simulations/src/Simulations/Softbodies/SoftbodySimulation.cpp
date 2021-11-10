#include "SoftbodySimulation.h"

SBS::SoftbodySimulation::SoftbodySimulation(olc::PixelGameEngine* pge)
	:
	SimulationBase(pge),
	m_worldData(nullptr),
	m_updateData(nullptr)
{}

void SBS::SoftbodySimulation::Init()
{
	// World Data
	float startX = m_screenWidth * 0.4f;
	float startY = m_screenHeight * 0.2f;
	glm::vec2 pos(startX, startY);

	float restLength = m_screenWidth < m_screenHeight ?
					  (m_screenWidth / REST_LENGTH_RATIO) : 
					  (m_screenHeight / REST_LENGTH_RATIO);

	float testFloat = 234.f;

	m_floatSliders =
	{
		new FloatSlider(&testFloat, 0.1f, 99.f, "firstEntry"),
		new FloatSlider(&testFloat, 0.1f, 99.f, "secondEntry"),
		new FloatSlider(&testFloat, 0.1f, 99.f, "thirdEntry"),
	};
}

void SBS::SoftbodySimulation::Update(float deltaTime)
{
	// Input for sliders
	if (m_floatSliders.size() > 0)
	{
		if (m_pge->GetKey(olc::DOWN).bPressed)
		{
			m_index = (m_index + 1) % m_floatSliders.size();
		}
		else if (m_pge->GetKey(olc::UP).bPressed)
		{
			--m_index;
	
			if (m_index < 0)
				m_index = m_floatSliders.size() - 1;
		}
		else if (m_pge->GetKey(olc::RIGHT).bHeld)
		{
			float currValue = *(m_floatSliders[m_index]->value);
			currValue += deltaTime;
			m_floatSliders[m_index]->value = &currValue;
		}
		else if (m_pge->GetKey(olc::LEFT).bHeld)
		{
			float currValue = *(m_floatSliders[m_index]->value);
			currValue -= deltaTime;
			m_floatSliders[m_index]->value = &currValue;
		}
	}

	// m_softBody->Update(deltaTime);
}

void SBS::SoftbodySimulation::Render()
{
	m_pge->Clear(olc::BLACK);

	// m_softBody->Render(m_pge);

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
