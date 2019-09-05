#pragma once
#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

#include "Ball.h"
#include "Block.h"
#include "GameSensor.h"
#include "TextureManager.h"
#include "UserInterface.h"
#include "listener.h"
#include "FileReader.h"

class Game : public sf::Drawable
{
private:

	sf::Sprite ssTemp;
	Block *bBlocks; //!< creates a pointer block object
	Ball *ballOne; //!< creates a pointer ball object

	sf::Texture m_tBackground; //!< applied to the sprite
	sf::Sprite m_sBackground; //!< so that a image is shown in the back

	GameSensor sensorOne; //!< sensor object
    TextureManager * TMOne; //!< a pointer object of texture manager 
	UserInterface UIOne; //!< sets strings to the screen and update them
	b2World * world; //!< box 2d world object

	b2Vec2 m_setGravity; //!< used to set the new gravity

	float m_viewRotation; //!< used to rotate the view
	float m_gameRotation; //!< used to determine the scale of rotation
	float m_ballRotation; //!< used to make the ball spin

	Listener listener; //!< a lisnter object
	FileReader m_FR; //!< a file reader object that contains get methods

	std::vector<sf::Vector2f> m_blockPos; //!< a vector of block positions
	std::vector<sf::Vector2f> m_blockScale; //!< a vecotr of block scales
	std::vector<std::pair<std::string, std::string>> m_images; //!< used to store map information for the TM

	sf::Vector2f m_sensorPos; //!< used to position the sensor
	sf::Vector2f m_sensorSca; //!< used to scale the sensor

	bool m_gameOver; //!< used to set the games state

	float m_time; //!< used to display the time
	short m_lives; //!< used to display lives


public:
	Game(); //!< constructor
	~Game(); //!< deconstructor
	void update(float pTimestep); //!< updates the objects within the game
	void processEvents(int pInputEvent);   //!< handles key inputs like tilt gravity
	void draw(sf::RenderTarget& target, sf::RenderStates states) const; //!< draw objects
	b2World *getWorld(); //!< if needed in main
	float getRot(); //!< gets the rotation for main
	void gameTextures(); //!< void method that passes textures to the manager 
	void gameBlocks(); //!< adds blocks to the game
	void setBackground(); //!< sets the background
	bool getGameOver(); //!< bool thats used in main to see if the game is over
	Ball *getBall();
	UserInterface getUI();
	TextureManager *getTextureManger();
};

