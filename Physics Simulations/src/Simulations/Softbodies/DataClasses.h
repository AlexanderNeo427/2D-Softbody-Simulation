#ifndef DATA_CLASSES
#define DATA_CLASSES

namespace SBS
{
	struct WorldData
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

	struct UpdateData
	{
		PhysicsData&   physicsData;
		PointMassData& pointmassData;
		SpringData&	   springData;
	};

	struct FloatSlider
	{
		float			 *value;
		const float		  min;
		const float		  max;
		const std::string name;

		FloatSlider(float*			   _value, 
					const float		   _min,
					const float		   _max,
					const std::string& _name) 
			:
			value(_value),
			min(_min),
			max(_max),
			name(_name)
		{};
	};
}

#endif