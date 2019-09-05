#include "TextureManager.h"

TextureManager * TextureManager::s_Instance = nullptr;

TextureManager::TextureManager(){
}

TextureManager::~TextureManager(){
}

void TextureManager::insertTexture(string path, string filename)
{
 
	sf::Texture temp;
	temp.loadFromFile(filename);
	m_mapOfTextures.insert(pair<string, sf::Texture>(string(path), sf::Texture(temp))); //inserts the textures into a map

}

sf::Texture TextureManager::getTexture(string name)
{
	sf::Texture temptexture;
	temptexture = m_mapOfTextures.at(name);  //gets the texture when i need it
	return temptexture;
}

void TextureManager::displayTextures()
{
	for (m_mapOfTexturesIter=--m_mapOfTextures.end(); m_mapOfTexturesIter!=--m_mapOfTextures.begin();--m_mapOfTexturesIter)
	{
		cout << (*m_mapOfTexturesIter).first << endl;   //iterates through the map to tell me the textures
	}
}

TextureManager * TextureManager::instance()
{
	if (s_Instance == nullptr)
	{
		s_Instance = new TextureManager();
	}
	return s_Instance;
}

