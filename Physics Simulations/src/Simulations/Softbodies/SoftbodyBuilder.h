#ifndef SOFTBODY_BUILDER
#define SOFTBODY_BUILDER

#include "SoftBody.h"
#include "DataClasses.h"
#include "../Physics.h"

namespace SBS
{
	class SoftbodyBuilder
	{
		static SoftBody* GenerateCube(const glm::vec2&		 pos, 
									  const PointMassParams& pointmassParams,

									  const int				 numPointsX, 
									  const int				 numPointsY, 
									  const float			 restLength)
		{
			return nullptr;
		}

		static SoftBody* GenerateSphere(const glm::vec2&	   pos, 
										const PointMassParams& pointmassParams, 
										const int			   numPoints, 
										const float			   restLength)
		{

			return nullptr;
		}
	};
}

#endif