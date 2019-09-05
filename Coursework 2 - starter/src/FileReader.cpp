#include "FileReader.h"

FileReader::FileReader(){

//	getFilePos();
	//getFileScale();
}

FileReader::~FileReader(){
}

std::vector<sf::Vector2f> FileReader::getFilePos()
{
	std::fstream posFile("../FileReader\\Pos.txt", std::ios_base::in);

	std::string posLine = "";

	std::vector<sf::Vector2f> vectorTemp;

	if (posFile.is_open()) {

		while (getline(posFile, posLine))
		{
			std::string str;
			std::istringstream isstr(posLine);
			isstr >> str;
			sf::Vector2f temp;

			if (str == "x") {
				isstr >> temp.x;
			}

			isstr >> str;

			if (str == "y") {
				isstr >> temp.y;
			}

			vectorTemp.push_back(temp);
		}
	}
	else {
		std::cout << "cannot open Pos File" << std::endl;
	}

	return vectorTemp;
	
}

std::vector<sf::Vector2f> FileReader::getFileScale()
{
	std::fstream scaleFile("../FileReader\\Scale.txt", std::ios_base::in);

	std::string scaleLine = "";

	std::vector<sf::Vector2f> vectorTemp;

	if (scaleFile.is_open()) {

		while (getline(scaleFile, scaleLine))
		{
			std::string str;
			std::istringstream isstr(scaleLine);
			isstr >> str;
			sf::Vector2f temp;

			if (str == "x") {
				isstr >> temp.x;

			}

			isstr >> str;

			if (str == "y") {
				isstr >> temp.y;

			}

			vectorTemp.push_back(temp);
		}
	}

	return vectorTemp;
}

std::vector<std::pair<std::string, std::string>> FileReader::getImageFile()
{
	std::fstream imageFile("../FileReader\\Images.txt", std::ios_base::in);

	std::string imageLine = "";

	std::vector<std::pair<std::string, std::string>> tempImage;

	if (imageFile.is_open()) {

		while (getline(imageFile, imageLine))
		{
			std::string str;
			std::istringstream isstr(imageLine);
			isstr >> str;

			std::string tempTag;
	        std::string tempLoc;
	
			if (str == "id:") {
				
				isstr >> tempTag;
			}

			isstr >> str;

			if (str == "file:") {
				isstr >> tempLoc;

			}

			tempImage.push_back(std::make_pair(tempTag, tempLoc));
		}
	}

	return tempImage;
}

sf::Vector2f FileReader::getFileSensorPos()     //Oringally i had a pair of sf::Vector 2fs combining the scale and positions 
{                                               //for some reason that made the sensor sometimes not work and it displayed no colour

	std::fstream sensorFile("../FileReader\\SensorPos.txt", std::ios_base::in);

	std::string sensorLine = "";

	if (sensorFile.is_open()) {

		while (getline(sensorFile, sensorLine))
		{
			std::string str;
			std::istringstream isstr(sensorLine);
			isstr >> str;

			sf::Vector2f temp;

			if (str == "x") {

				isstr >> temp.x;
			}

			isstr >> str;

			if (str == "y") {
				isstr >> temp.y;

			}


			return temp;

		}
		
	}
}

sf::Vector2f FileReader::getFileSensorScale()
{
	std::fstream sensorFile("../FileReader\\SensorScale.txt", std::ios_base::in);

	std::string sensorLine = "";

	if (sensorFile.is_open()) {

		while (getline(sensorFile, sensorLine))
		{
			std::string str;
			std::istringstream isstr(sensorLine);
			isstr >> str;

			sf::Vector2f temp;

			if (str == "xs") {

				isstr >> temp.x;
			}

			isstr >> str;

			if (str == "ys") {
				isstr >> temp.y;

			}

			return temp;
		}
	}		
		
}






