#ifndef SOFTBODY_SIMULATION
#define SOFTBODY_SIMULATION

#include "../SimulationBase.h"
#include "SoftBodyBuilder.h"

namespace SBS
{
	class SoftbodySimulation : public SimulationBase
	{
	private:
		// Point-masses
		static const int NUM_POINTS_X	= 12;
		static const int NUM_POINTS_Y	= 9;
		const float		 POINTMASS_SIZE = 9.f;
		const float		 POINTMASS_MASS = 1.f;

		// Springs
		const float	REST_LENGTH_RATIO = 30.f;
		const float STIFFNESS		  = 690.f;
		const float	DAMP_FACTOR		  = 0.69f;

		// Physics
		const float	GRAVITY = 100.f;

		// Environment
		const float	BORDER_RESTITUTION = 0.5f;
		const float BORDER_FRICTION	   = 0.75f;
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
