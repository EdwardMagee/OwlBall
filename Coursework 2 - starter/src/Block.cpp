#include "Block.h"



Block::Block(sf::Texture texture)
{
	m_tTemp = texture;
}

void Block::constructBlock(sf::Vector2f pos, sf::Vector2f size, b2World * pWorld)
{
	sf::RectangleShape sTemp;   // creates a temp and pushes it into a vector
	m_rsBlocks.push_back(sTemp);
	int index = m_rsBlocks.size() - 1;
	this->m_size = size;

	m_rsBlocks[index].setSize(sf::Vector2f(size.x, size.y));  //Sets all the information on the block
	m_rsBlocks[index].setPosition(pos.x, pos.y);
	m_rsBlocks[index].setFillColor(sf::Color::White);
	m_rsBlocks[index].setTexture(&m_tTemp);
	m_rsBlocks[index].setOrigin(this->m_size.x * 0.5, this->m_size.y * 0.5);

	m_bodyDef.type = b2_kinematicBody;
	m_bodyDef.position.Set(m_rsBlocks[index].getPosition().x, m_rsBlocks[index].getPosition().y);
	m_bodyDef.angle = 0.f;

	m_body = pWorld->CreateBody(&m_bodyDef);

	m_blockShape.SetAsBox(m_rsBlocks[index].getSize().x * 0.5f, m_rsBlocks[index].getSize().y * 0.5f);
	m_blockShape.m_radius = 0.0f;

	m_FixtureDef.density = m_cfDensity;
	m_FixtureDef.friction = m_cfFriction;
	m_FixtureDef.restitution = m_cfRestitution;
	m_FixtureDef.shape = &m_blockShape;

	m_body->CreateFixture(&m_FixtureDef);
}

Block::Block()
{
}

Block::~Block()
{
}


void Block::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (auto it = m_rsBlocks.cbegin(); it != m_rsBlocks.cend(); ++it)
	{
		target.draw(*it);    //draws the block
	}
	
}

