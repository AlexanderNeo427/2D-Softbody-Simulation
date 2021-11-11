#ifndef DATA_CLASSES
#define DATA_CLASSES

namespace SBS
{
	struct BoundaryData
	{
		glm::vec2 boundsX;
		glm::vec2 boundsY;
	};

	struct PhysicsData
	{
		glm::vec2 gravity;
		float	  coefFriction;
		float	  coefRestitution;
	};

	struct PointMassData
	{
		float	   radius;
		float	   mass;
		olc::Pixel color;
	};

	struct SpringData
	{
		float stiffness;
		float dampFactor;
	};

	struct WorldData
	{
		BoundaryData&  boundaryData;
		PhysicsData&   physicsData;
		PointMassData& pointmassData;
		SpringData&	   springData;
	};
}

#endif