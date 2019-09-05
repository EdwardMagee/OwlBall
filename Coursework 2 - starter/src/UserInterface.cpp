#include "UserInterface.h"

UserInterface::UserInterface()
{

	if (!m_gameFont.loadFromFile("../Fonts/ArialTh.ttf"))     //gets the font
	{
		std::cout << "Failed to get Font" << std::endl;
	}

     m_tScore.setFont(m_gameFont);
	 m_time.setFont(m_gameFont);
	 m_tLives.setFont(m_gameFont);
	 m_time.setCharacterSize(15);
	 m_time.setPosition(30, -1);
	 m_tLives.setCharacterSize(15);
	 m_tLives.setPosition(124, -1);
	 m_tScore.setCharacterSize(76);         //sets all the information of the strings
	 m_tScore.setPosition(100, 100);

}


UserInterface::~UserInterface()
{
}

sf::Text UserInterface::getTextScore()  //get methods
{
	return m_tScore;
}

sf::Text UserInterface::getTextTime()
{
	return m_time;
}

sf::Text UserInterface::getTextLives()
{
	return m_tLives;
}

void UserInterface::setTime(float p_time)
{
	std::string tempTime = "Time: " + std::to_string((int)p_time);   //gets a float converts it into a string 
	m_time.setString(tempTime);       //sets the string to a text
}

void UserInterface::setLives(short p_lives)
{
	std::string tempLives = "Lives: " + std::to_string(p_lives);     //used to set the short to a string 
	m_tLives.setString(tempLives);
}

void UserInterface::setScore(short p_sLives, float p_sTime)
{
	int scoreTemp;

	scoreTemp = 0;

	for (int i = 0; i < 4; i++)           //depeneding on the lives the score will be added with a diffrent int
	{
		if (p_sLives == i) {
			scoreTemp += 1000 * i;
		}
		else {
			scoreTemp += 0;
		}
		
	}

	for (int j = 0; j < 32; j++)      //the faster you are the more score you will get
	{
		if ((int)p_sTime == j) {
			scoreTemp += 100 * j;
		}

	}

	std::string tempFinalScore = "Final Score : " + std::to_string(scoreTemp);  //sets the final score to a text
	m_tScore.setString(tempFinalScore);
}


