#pragma once

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

class PhysicalObject
{
protected:

	const float m_cfDensity = 10.0f; //!< density of all physical objects
	const float m_cfFriction = 0.0f; //!< friction of all physical objects
	const float m_cfRestitution = 0.35f; //!< restitution of all physical objects
	b2Body * m_body = nullptr; //!< creates m_body and makes it null


};


