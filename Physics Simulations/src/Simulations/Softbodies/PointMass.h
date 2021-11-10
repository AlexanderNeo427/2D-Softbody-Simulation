#ifndef POINT_MASS
#define POINT_MASS

#include "glm/geometric.hpp"
#include "glm/common.hpp"
#include "glm/vec2.hpp"
#include "olcPixelGameEngine.h"

namespace SBS
{
	struct PointMass
	{
		glm::vec2  pos;
		glm::vec2  vel;
		glm::vec2  force;
		float	   mass;
		float	   radius;
		olc::Pixel color;

		PointMass(const glm::vec2& _pos, float _mass, float _radius, const olc::Pixel& _color)
			:
			pos(_pos), 
			vel(0.f, 0.f), 
			force(0.f, 0.f),
			mass(_mass),
			radius(_radius),
			color(_color)
		{}

		void AddForce(const glm::vec2& _force)
		{
			force += _force;
		}

		void Integrate(float deltaTime)
		{
			vel += (force / mass) * deltaTime;
			pos += vel * deltaTime;
		}
	};
}

#endif
