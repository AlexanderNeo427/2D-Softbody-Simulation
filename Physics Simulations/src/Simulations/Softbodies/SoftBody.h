#ifndef SOFT_BODY
#define SOFT_BODY

#include "Spring.h"
#include "DataClasses.h"

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

		void Update(float deltaTime, WorldData* worldData);
		void Render(olc::PixelGameEngine* pge);
	private:
		void Constrain(PointMass* pMass, const BoundaryData& boundary, const PhysicsData& physics);
		bool IsColliding(PointMass* p1, PointMass* p2, const PhysicsData& physics);
		void ResolveCollision(PointMass* p1, PointMass* p2, const PhysicsData& physics);
	private:
		std::vector<PointMass*> m_pointMasses;
		std::vector<Spring*>	m_springs;
	};
}

#endif