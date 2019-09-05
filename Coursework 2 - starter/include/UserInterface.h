#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class UserInterface
{
private:

	sf::Font m_gameFont; //!< used to get font
	sf::Text m_tScore; //!< used to store score
	sf::Text m_time;  //!< used to store time
	sf::Text m_tLives; //!< used to display lives

public:

	sf::Text getTextScore(); //!< gets the text score
	sf::Text getTextTime(); //!< used to get the text time 
	sf::Text getTextLives(); //!< gets the text lives

	void setTime(float pTime); //!< sets the time 
	void setLives(short pLives); //!< sets the games lives to the text
	void setScore(short pLives, float pTime); //!< sets the score to the text

	UserInterface(); //!< constructor
	~UserInterface(); //!< deconstructor
};

