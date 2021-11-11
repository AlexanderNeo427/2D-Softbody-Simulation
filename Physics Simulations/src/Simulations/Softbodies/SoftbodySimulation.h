#ifndef SOFTBODY_SIMULATION
#define SOFTBODY_SIMULATION

#include "../SimulationBase.h"
#include "SoftBodyBuilder.h"

namespace SBS
{
	class SoftbodySimulation : public SimulationBase
	{
	private:
		// Cube pointmass
		static const int NUM_POINTS_X	= 8;
		static const int NUM_POINTS_Y	= 12;

		// Sphere pointmass
		static const int NUM_POINTS = 21;
		static const int RADIUS		= 100.f;
		
		// Point-masses
		const float POINTMASS_SIZE = 7.f;
		const float POINTMASS_MASS = 1.f;

		// Springs
		const float	REST_LENGTH_RATIO = 30.f;
		const float STIFFNESS		  = 150.f;
		const float	DAMP_FACTOR		  = 0.69f;

		// Physics
		const float	GRAVITY = 120.f;

		// Environment
		const float	COEF_RESTITUTION = 0.69f;
		const float COEF_FRICTION	 = 0.25f;
	public:
		SoftbodySimulation(olc::PixelGameEngine* pge);

		void Init();
		void Update(float deltaTime);
		void Render();
		void Exit();
	private:
		void InitializeWorldData();
		void UpdateWorldData();
	private:
		SoftBody*  m_softBody;
		WorldData* m_worldData;
	};
}

#endif
