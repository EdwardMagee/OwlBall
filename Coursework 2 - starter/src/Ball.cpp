#include "Ball.h"



Ball::Ball(float x, float y, float radius, b2World *pWorld, sf::Texture texture)
{
	 
	m_temp = texture;           //used to store the texture that is then applied to the ball
	m_circle.setPosition(x, y);
	m_circle.setRadius(radius);
	m_circle.setOrigin(radius, radius);     //sets the position, raduis, orgin the m_circle
	m_circle.setRotation(0);
	
	m_circle.setTexture(&m_temp);

	m_bodyDef.type = b2_dynamicBody;
	m_bodyDef.position.Set(m_circle.getPosition().x, m_circle.getPosition().y);     //sets the bodydef
	m_bodyDef.linearVelocity = b2Vec2(10.0f, 10.0f);    
	

	m_body = pWorld->CreateBody(&m_bodyDef);      //sets the body to the world

	m_circleShape.m_radius = m_circle.getRadius();

	m_pFixtureDef.density = m_cfDensity;
	m_pFixtureDef.friction = m_cfFriction;
	m_pFixtureDef.restitution = m_cfRestitution;
	m_pFixtureDef.shape = &m_circleShape;
	
	m_body->CreateFixture(&m_pFixtureDef);
	m_body->SetAngularVelocity(-1.0f); 
}

Ball::Ball(){
}

Ball::~Ball(){
}

sf::Vector2f Ball::getBallPos()
{
	return m_circle.getPosition();  //gets the balls position 
}

void Ball::resetBall(float x, float y){
	m_circle.setPosition(x, y);
	m_body->SetTransform(b2Vec2(x, y), 0); //used to reset the ball when time hits 0
	
}


void Ball::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_circle);  //draws the ball
}

void Ball::updateBall(float p_Rot) {
	m_circle.setPosition(m_body->GetPosition().x, m_body->GetPosition().y);
	
	m_body->SetAngularVelocity(p_Rot);     //used to update the balls position and rotation
	
	
	m_circle.setRotation(m_body->GetAngle() * (-180.f / 3.145f)); 

	
}
