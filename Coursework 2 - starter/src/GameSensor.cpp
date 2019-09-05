#include "GameSensor.h"



GameSensor::GameSensor(sf::Vector2f pos, sf::Vector2f size, b2World * pWorld)
{
	b2PolygonShape blockShape;
	b2BodyDef bodyDef;
	b2FixtureDef pFixtureDef;


	m_sensorShape.setSize(sf::Vector2f(size.x, size.y));   //sets the world 
	m_sensorShape.setPosition(pos.x, pos.y);
	m_sensorShape.setFillColor(sf::Color::Transparent);
	m_sensorShape.setOrigin(size.x * 0.5, size.y * 0.5);

	bodyDef.type = b2_staticBody;
	bodyDef.position.Set(pos.x, pos.y);
	bodyDef.angle = 0.f;

	m_body = pWorld->CreateBody(&bodyDef);


	blockShape.SetAsBox(size.x * 0.5f, size.y * 0.5f);
	blockShape.m_radius = 0.0f;

	pFixtureDef.shape = &blockShape;
	pFixtureDef.isSensor = true;

	m_active = false;

	m_body->CreateFixture(&pFixtureDef);
}


GameSensor::~GameSensor()
{
}
void GameSensor::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(m_sensorShape); //draws the sensor
}
