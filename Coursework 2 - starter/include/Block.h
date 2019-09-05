#pragma once
#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include "PhysicalObject.h"
#include <vector>
#include <iostream>

class Block : public sf::Drawable, public PhysicalObject 
{
private:
	std::vector<b2Body> *blockBody; //!< Vector of block bodies
	std::vector<sf::RectangleShape> m_rsBlocks; //!< Vector of sfml objects
	b2PolygonShape m_blockShape; //!< shape of the block
	sf::Texture m_tTemp; //!< a temp for the texture
	b2BodyDef m_bodyDef; //!< defines the bodyDef
	b2FixtureDef m_FixtureDef; //!< defines the fixture
	sf::Vector2f m_size; //!< sets the size of the block
public:
	Block(); //!< constructor
	Block(sf::Texture pTexture); //!< constructs a type of block
	void constructBlock(sf::Vector2f pPos, sf::Vector2f pSize, b2World *pWorld);
	~Block(); //!< deconstructor
	void draw(sf::RenderTarget& target, sf::RenderStates states) const; //!< draws a vector of blocks

};

