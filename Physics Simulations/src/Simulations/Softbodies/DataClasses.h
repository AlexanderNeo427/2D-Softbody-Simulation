#ifndef DATA_CLASSES
#define DATA_CLASSES

namespace SBS
{
	struct WorldData
	{
		WorldData(const glm::vec2& worldMin, const glm::vec2& worldMax)
			:
			m_worldMin(worldMin),
			m_worldMax(worldMax)
		{};
	private:
		glm::vec2 m_worldMin;
		glm::vec2 m_worldMax;
	};

	struct PointMassParams
	{
		glm::vec2  pos;
		float	   radius;
		float	   mass;
		olc::Pixel color;
	};

	class UpdateData
	{
	public:
		UpdateData(olc::PixelGameEngine* pge) : m_pge(pge) {};


	private:
		olc::PixelGameEngine* m_pge;
	};
}

#endif