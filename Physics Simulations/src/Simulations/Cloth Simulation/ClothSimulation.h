#ifndef CLOTH_SIMULATION
#define CLOTH_SIMULATION

#include "../SimulationBase.h"
#include "glm/common.hpp"
#include "glm/vec2.hpp"

class ClothSimulation : public SimulationBase
{
public:
	struct PointMass
	{
		glm::vec2 pos;
		glm::vec2 oldPos;
	};
public:
	ClothSimulation(olc::PixelGameEngine* pge);

	void Init()					 override;
	void Update(float deltaTime) override;
	void Render()				 override;
	void Exit()					 override;
private:
	std::vector<PointMass*> m_cloth;
};

#endif