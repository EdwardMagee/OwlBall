#pragma once
#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include "PhysicalObject.h"
#include <iostream>

class Ball : public sf::Drawable, public PhysicalObject
{
private: 

	b2CircleShape m_circleShape; //!< shape of the circle
	sf::CircleShape m_circle; //!< SFML for the circle
	b2BodyDef m_bodyDef; //!< defines the body of the ball
	b2FixtureDef m_pFixtureDef; //!< defines the fixture of the ball
	sf::Texture m_temp; //!< Holds a texture for the ball
public:
	Ball(float px, float py, float pRadius, b2World *pWorld, sf::Texture pTexture);  //!< Constructs the ball
	Ball(); //!< Default Constructor
	~Ball(); //!< Deconstructor
	sf::Vector2f getBallPos(); //!< used to get the ball pos for view
	void resetBall(float px, float py); //!< resets ball when lives--
	void updateBall(float p_Rot);  //!< Update is used to rotate the ball
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;  //!< Draws the ball
	
};

