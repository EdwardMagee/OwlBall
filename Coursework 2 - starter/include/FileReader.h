#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

class FileReader
{
public:
	FileReader();
	~FileReader();

	std::vector<sf::Vector2f> getFilePos(); //!< gets the blocks positions
	std::vector<sf::Vector2f> getFileScale(); //!< gets the scales for blocks
	std::vector <std::pair<std::string, std::string>> getImageFile(); //!< gets strings that are later used in the texture manager
	sf::Vector2f getFileSensorPos(); //!< gets sensor pos from file
	sf::Vector2f getFileSensorScale(); //!< gets sensor scale from file
	
};
