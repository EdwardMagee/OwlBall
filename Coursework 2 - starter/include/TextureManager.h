#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include <iostream>

using namespace std;

class TextureManager
{
private:
	 map<string, sf::Texture> m_mapOfTextures; //!< contains all the textures
	 map<string, sf::Texture>::iterator m_mapOfTexturesIter; //!< used to iterate through textures
	 static TextureManager * s_Instance; //!< creates a object of texture manager
	 TextureManager();	//!< private constructor
	 
public:
    ~TextureManager(); //!< deconstructor
	static TextureManager * instance(); //!< make the class a singleton 
	void insertTexture(string pPath, string pFilename); //!< inserts a texture
	sf::Texture getTexture(string pFileName); //!< used to get the texture
	void displayTextures(); //!< display all textures to console
	TextureManager(TextureManager const&) = delete; //!< Deletes the assigment operator
	TextureManager& operator=(TextureManager const&) = delete; //!< deletes the copy operator
};
