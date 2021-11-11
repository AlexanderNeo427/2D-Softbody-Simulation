#ifndef DATA_CLASSES
#define DATA_CLASSES

namespace SBS
{
	struct BoundaryData
	{
		glm::vec2 min;
		glm::vec2 max;
	};

	struct PhysicsData
	{
		glm::vec2 gravity;
		float	  coefFriction;
		float	  coefRestitution;
	};

	struct SpringData
	{
		float stiffness;
		float dampFactor;
	};

	struct PointMassData
	{
		float radius;
		float mass;
	};

	struct WorldData
	{
		BoundaryData  boundaryData;
		PhysicsData   physicsData;
		PointMassData pointmassData;
		SpringData	  springData;
	};
}

#endif