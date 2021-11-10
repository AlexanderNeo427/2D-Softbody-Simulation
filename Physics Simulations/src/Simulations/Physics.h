#ifndef PHYSICS
#define PHYSICS

#include "glm/vec2.hpp"
#include "glm/common.hpp"
#include "glm/glm.hpp"

struct Physics
{
	/**
	 * @brief You don't know what gravity is?!
	 */
	static const glm::vec2& Gravity() { return glm::vec2(0.f, -9.8f); }

	/**
	 * @brief		Coefficient of Friction
	 * @description 
	 */
	static const float COF() { return 0.5f; }

	/**
	 * @brief Coefficient of Restitution
	 * @description
	 */
	static const float COR() { return 0.5f; }
};

#endif