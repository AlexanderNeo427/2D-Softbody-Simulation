#ifndef APPLICATION_H
#define APPLICATION_H

// All scenes here
#include "Simulations/Cloth Simulation/ClothSimulation.h"

class Application : public olc::PixelGameEngine
{
public:
	Application();
	~Application();

	bool OnUserCreate()				   override;
	bool OnUserUpdate(float deltaTime) override;
	bool OnUserDestroy()			   override;
private:
	SimulationBase* m_simulation;
};

#endif