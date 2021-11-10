#ifndef SPRING
#define SPRING

#include "PointMass.h"

namespace SBS
{
	struct Spring
	{
		PointMass* p1;
		PointMass* p2;
		float	   restLength;

		Spring(PointMass* _p1,
			   PointMass* _p2,
			   float	  _restLength)
			:
			p1(_p1),
			p2(_p2),
			restLength(_restLength)
		{}

		const glm::vec2& CalcSpringLinearForceP21(float stiffness, float dampFactor) const
		{
			glm::vec2 p21 = glm::normalize(p1->pos - p2->pos);
			return CalcHookesLawP21(stiffness) * p21 + CalcDampForceP21(dampFactor) * p21;
		}
	private:
		const float CalcDampForceP21(float dampFactor) const
		{
			glm::vec2 v21 = p1->vel - p2->vel;
			glm::vec2 d21 = p1->pos - p2->pos;
			return glm::dot(v21, d21) * dampFactor / glm::length(d21);
		}
		const float CalcHookesLawP21(float stiffness) const
		{
			float distance = glm::distance(p1->pos, p2->pos);
			float displacement = distance - restLength;
			return stiffness * displacement;
		}
	};
}

#endif

