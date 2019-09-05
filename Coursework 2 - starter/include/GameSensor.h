#pragma once

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ball.h"
#include "Block.h"
#include "TextureManager.h"


class GameSensor :  public sf::Drawable// public b2ContactListener,
{
private:

	bool m_active; //!< bool that is used to tell if active or not
	 b2Body* m_body; //!< body of the sensor
	sf::RectangleShape m_sensorShape; //!< shape of the sensor

public:
	GameSensor() {} //!< constructor
	GameSensor(sf::Vector2f pPos, sf::Vector2f pSize, b2World * pWorld);
	~GameSensor(); //!<deconstructor
	void draw(sf::RenderTarget& target, sf::RenderStates states) const; //!< draws the object
	void setActive() { m_active = true; } //!< sets m_active to true
	bool isActive() { return m_active;  } //!< gets m_active
	void setUserData() {m_body->SetUserData(this);} //!<sets the user data
		

};

