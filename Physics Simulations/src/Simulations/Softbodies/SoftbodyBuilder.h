#ifndef SOFTBODY_BUILDER
#define SOFTBODY_BUILDER

#include "SoftBody.h"
#include "DataClasses.h"

namespace SBS
{
	class SoftbodyBuilder
	{
		SoftbodyBuilder(WorldData* worldData) 
			:
			m_worldData(worldData)
		{}

		SoftBody* GenerateCube(const glm::vec2&		position, 
							   const PointMassData& pointmassData,
							   const glm::ivec2&	numPoints, 
							   const float			restLength)
		{
			//std::vector<PointMass*> m_pointMasses;
			//std::vector<Spring*>	m_springs;

			//// Initialize point-masses
			//glm::vec2 pos = position;
			//for (int y = 0; y < numPoints.y; ++y)
			//{
			//	for (int x = 0; x < numPoints.x; ++x)
			//	{
			//		float r = 255;
			//		float g = 255 - (x / numPoints.x) * 255;
			//		float b = 255 - (y / numPoints.y) * 255;
			//		olc::Pixel color(r, g, b);

			//		PointMass* pMass = new PointMass(pos, pointmassParams.mass, pointmassParams.radius, color);
			//		// pMass->restitution = 0.3;
			//		m_pointMasses.emplace_back(pMass);
			//		pos.x += restLength;
			//	}
			//	pos.y += restLength;
			//	pos.x = position.x;
			//}

			//std::vector<glm::ivec2> directions
			//{
			//	glm::ivec2(2, -1),
			//	glm::ivec2(2, 1),
			//	glm::ivec2(1, 0),
			//	glm::ivec2(1, 1),
			//	glm::ivec2(0, 1),
			//	glm::ivec2(1, 2),
			//	glm::ivec2(-1, 2),
			//};

			//// Initialize springs
			//for (int i = 0; i < m_pointMasses.size(); ++i)
			//{
			//	PointMass* currPM = m_pointMasses[i];
			//	int x = i % numPoints.x;
			//	int y = i / numPoints.x;

			//	std::vector<PointMass*> surroundingPointMasses;

			//	for (glm::ivec2 dir : directions)
			//	{
			//		glm::ivec2 next(x + dir.x, y + dir.y);

			//		if (next.x < 0 || next.x >= numPoints.x ||
			//			next.y < 0 || next.y >= numPoints.y)
			//			continue;

			//		int nextIndex = (next.y * numPoints.x) + next.x;
			//		surroundingPointMasses.emplace_back(m_pointMasses[nextIndex]);
			//	}

			//	for (PointMass* otherPM : surroundingPointMasses)
			//	{
			//		float distance = glm::distance(currPM->pos, otherPM->pos);
			//		Spring* spring = new Spring(currPM, otherPM, distance, STIFFNESS, DAMP_FACTOR);
			//		m_springs.emplace_back(spring);
			//	}
			//}
			//for (int y = 0; y < numPoints.y - 1; ++y)
			//{
			//	for (int x = numPoints.x - 1; x >= 1; --x)
			//	{
			//		int nextY = y + 1;
			//		int nextX = x - 1;

			//		PointMass* p1 = m_pointMasses[(y * numPoints.x) + x];
			//		PointMass* p2 = m_pointMasses[(nextY * numPoints.x) + nextX];

			//		float length = glm::distance(p1->pos, p2->pos);

			//		Spring* spring = new Spring(p1, p2, length, STIFFNESS, DAMP_FACTOR);
			//		m_springs.emplace_back(spring);
			//	}
			//}

			return nullptr;
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