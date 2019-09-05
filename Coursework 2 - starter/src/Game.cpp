#include "Game.h"


Game::Game()
{
	

	m_lives = 3;  //starting lives
	m_time = 30;   //Game timer 

	m_gameOver = false;      //game is set to false at start so it continues playing

    m_setGravity = b2Vec2(0.f, 9.8f);    //starting gravity

    m_blockPos = m_FR.getFilePos();
	m_blockScale = m_FR.getFileScale();    //I do this so i only read from the file once rather then calling the file each time i wanna use it
	m_images = m_FR.getImageFile();
	m_sensorPos = m_FR.getFileSensorPos();
	m_sensorSca = m_FR.getFileSensorScale();

	gameTextures();   //sets the games textures
	world = new b2World(b2Vec2(0.f, 0.f));
	ballOne = new Ball(4.0f, 4.0f, 0.25f, world, TMOne->instance()->getTexture("Owl")); //creates the ball
	gameBlocks();       //creates all the blocks within the game 
	setBackground();     //creates the game background
	
	world->SetGravity(b2Vec2(m_setGravity));
	world->SetContactListener(&listener);

	ssTemp.setTexture(TMOne->instance()->getTexture("Owl"));

	sensorOne = GameSensor(sf::Vector2f(m_sensorPos.x, m_sensorPos.y), (sf::Vector2f(m_sensorSca.x, m_sensorSca.y)), world);  //creates the game sensor
	
	sensorOne.setUserData();
	GameSensor * p = &sensorOne;

	m_gameRotation = 10.f;     //rotation speed
	
}

Game::~Game()
{
	delete ballOne;
	delete bBlocks;
	delete world;
	ballOne = nullptr;
	bBlocks = nullptr;
	world = nullptr;
}

void Game::update(float timestep) {

	ballOne->updateBall(m_ballRotation); //updates the ball

	sensorOne.setUserData();

	if (sensorOne.isActive()){
		m_gameOver = true;         //when the ball hits the sensor the game over will be true
	}

	m_time -= timestep;         //used to reduce time

	if (m_time < 0){
		
		m_lives--;
		ballOne->resetBall(4.0f, 4.0f);     //if time goes to 0 the player will lose a live, the ball and time will reset
		m_time = 30;

	}

	if (m_lives == 0){
		m_time = 0;
		
		m_gameOver = true;     //if the player runs out of lives the game will be over
	}

	UIOne.setLives(m_lives);        //sets the text in the UI class
	UIOne.setTime(m_time);            
	UIOne.setScore(m_lives, m_time);


}

void Game::processEvents(int inputEvent) {

	switch (inputEvent)
	{
	case sf::Keyboard::Left:        //when the left key is pressed

		m_viewRotation += m_gameRotation;  //Rotates the view by ten

		if(m_ballRotation < 10)
		m_ballRotation += 1.0f;         //rotates the ball


		float rotationTemp;
		rotationTemp = (m_gameRotation * (3.145f / 180.f));  //Gravity took a radain instead of degrees 

		m_setGravity.x = cos(rotationTemp) * world->GetGravity().x - m_setGravity.y * sin(rotationTemp);   //used a rotation matrix to rotate the gravity
		m_setGravity.y = sin(rotationTemp) * world->GetGravity().x + m_setGravity.y * cos(rotationTemp);

		world->SetGravity(b2Vec2(m_setGravity.x, m_setGravity.y));    //sets the new gravity
		
		break;

	case sf::Keyboard::Right:   //same as the prevoius code but for the right key

		m_viewRotation -= m_gameRotation;

		if (m_ballRotation > -10)
		m_ballRotation += -1.0;

		float  rotationTempR;
		rotationTempR = -m_gameRotation * (3.145f / 180.f);

		m_setGravity.x = cos(rotationTempR) * world->GetGravity().x - m_setGravity.y * sin(rotationTempR);
		m_setGravity.y = sin(rotationTempR) * world->GetGravity().x + m_setGravity.y * cos(rotationTempR);

		world->SetGravity(b2Vec2(m_setGravity.x, m_setGravity.y));

		cout << m_setGravity.x << m_setGravity.y << endl;
		
		break;

	default:
		break;
	}
		
	
}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	//target.draw(ssTemp);
	target.draw(m_sBackground);
	target.draw(*ballOne);
	target.draw(*bBlocks);
	target.draw(sensorOne);      //draws everything in the game
	
}

b2World *Game::getWorld()
{
	return world;      //used to get the world
}

float Game::getRot()
{
	return m_viewRotation;     //used to get the rotation
}

void Game::gameTextures()
{
	for (int i = 0; i < m_images.size(); i++)
	{ 
		TMOne->instance()->insertTexture(m_images[i].first, m_images[i].second);     //inserts all the textures into the singleton
	}

	TMOne->instance()->displayTextures();     //displays all the games textures 
	 
}

void Game::gameBlocks()
{
	bBlocks = new Block(TMOne->instance()->getTexture("Wood")); //creates a type of block

	for (int i = 0; i < m_blockPos.size(); i++) {

		bBlocks->constructBlock(sf::Vector2f(m_blockPos[i].x, m_blockPos[i].y), 
			(sf::Vector2f(m_blockScale[i].x, m_blockScale[i].y)), world);       //constructs all of the game blocks in a for loop

	}
}

void Game::setBackground()
{
	m_tBackground = TMOne->instance()->getTexture("Sky");
	m_sBackground.setTexture(m_tBackground);
	m_sBackground.setPosition(-8.0f, -8.0f);
	m_sBackground.setScale(0.021f, 0.04f); //Very Big Image
	
}

bool Game::getGameOver()
{
	return m_gameOver; //  gets the game over 
}

Ball * Game::getBall()
{
	return ballOne;  //gets ballOne
}

UserInterface Game::getUI()
{
	return UIOne;   //gets the UI
}

TextureManager * Game::getTextureManger()
{
	return TMOne;  //gets the TM
}



