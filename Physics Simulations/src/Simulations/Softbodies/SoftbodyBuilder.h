#ifndef SOFTBODY_BUILDER
#define SOFTBODY_BUILDER

#include "SoftBody.h"
#include "DataClasses.h"

namespace SBS
{
	struct SoftbodyBuilder
	{
		SoftbodyBuilder(WorldData* worldData) 
			:
			m_worldData(worldData)
		{}

		SoftBody* GenerateCube(const glm::vec2&		position, 
							   const PointMassData& pointmassData,
							   const SpringData&	springData,
							   const glm::ivec2&	numPoints, 
							   const float			restLength)
		{
			std::vector<PointMass*> pointMasses;
			std::vector<Spring*>	springs;

			// Initialize point-masses
			glm::vec2 pos = position;
			for (int y = 0; y < numPoints.y; ++y)
			{
				for (int x = 0; x < numPoints.x; ++x)
				{
					float r = 255.f;
					float g = 255.f - ((float)x / (float)numPoints.x) * 255.f;
					float b = 255.f - ((float)y / (float)numPoints.y) * 255.f;
					olc::Pixel color(r, g, b);

					PointMass* pMass = new PointMass(pos, pointmassData.mass, pointmassData.radius, color);
					// pMass->restitution = 0.3;
					pointMasses.emplace_back(pMass);
					pos.x += restLength;
				}
				pos.y += restLength;
				pos.x = position.x;
			}

			std::vector<glm::ivec2> directions
			{
				glm::ivec2(2, -1),
				glm::ivec2(2, 1),
				glm::ivec2(1, 0),
				glm::ivec2(1, 1),
				glm::ivec2(0, 1),
				glm::ivec2(1, 2),
				glm::ivec2(-1, 2),
			};

			// Initialize springs
			for (int i = 0; i < pointMasses.size(); ++i)
			{
				PointMass* currPM = pointMasses[i];
				int x = i % numPoints.x;
				int y = i / numPoints.x;

				std::vector<PointMass*> surroundingPointMasses;

				for (glm::ivec2 dir : directions)
				{
					glm::ivec2 next(x + dir.x, y + dir.y);

					if (next.x < 0 || next.x >= numPoints.x ||
						next.y < 0 || next.y >= numPoints.y)
						continue;

					int nextIndex = (next.y * numPoints.x) + next.x;
					surroundingPointMasses.emplace_back(pointMasses[nextIndex]);
				}

				for (PointMass* otherPM : surroundingPointMasses)
				{
					float restLength = glm::distance(currPM->pos, otherPM->pos);
					Spring* spring = new Spring(currPM, otherPM, restLength);
					springs.emplace_back(spring);
				}
			}
			for (int y = 0; y < numPoints.y - 1; ++y)
			{
				for (int x = numPoints.x - 1; x >= 1; --x)
				{
					int nextY = y + 1;
					int nextX = x - 1;

					PointMass* p1 = pointMasses[(y * numPoints.x) + x];
					PointMass* p2 = pointMasses[(nextY * numPoints.x) + nextX];

					Spring* spring = new Spring(p1, p2, glm::distance(p1->pos, p2->pos));
					springs.emplace_back(spring);
				}
			}

			return new SoftBody(pointMasses, springs);
		}

		SoftBody* GenerateSphere(const glm::vec2&	  position, 
								 const PointMassData& pointmassData,
								 const WorldData&	  worldData,
								 const int			  numPoints, 
								 const float		  restLength)
		{

			return nullptr;
		}
	private:
		WorldData* m_worldData;
	};
}

#endif