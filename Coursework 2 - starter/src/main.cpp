
#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "TextureManager.h"


void main() 
{

	sf::RenderWindow window(sf::VideoMode(1280, 960), "Box2DGame"); //creates the first window
	
	
	sf::Clock timer;
	float fFrameTime = 1.f / 60.f;   //used for framerate
	float fElapsedTime = 0.f;
	TextureManager * textureManager;  //used to get textures
	
	sf::Vector2f worldSize(18.0f, 14.0f);

	sf::View gameView;
	gameView.setCenter(worldSize.x / 2, worldSize.y / 2);  //creates the main view 
	gameView.setSize(worldSize.x, worldSize.y);
	gameView.zoom(0.36f);
	
	sf::View miniView;
	miniView.setViewport(sf::FloatRect(0.f, 0.f, 6.f, 4.0f));   //creates the mini view
	miniView.setCenter(1280 / 2, 960 / 2);
	miniView.setSize(1280, 960);
	miniView.zoom(1.05f);
	

	sf::RectangleShape RS(sf::Vector2f(26.5f, 33.5f));   //first rectangle
	RS.setFillColor(sf::Color(1, 1, 1));

	sf::RectangleShape RS2(sf::Vector2f(176.5f, 16.5f)); //second rectangle
	RS2.setFillColor(sf::Color(1, 1, 1));

	Game game; 



		while (window.isOpen() && !game.getGameOver()) //the window will be open if the game is not over
		{
			sf::Event event;

			while (window.pollEvent(event))
			{
				switch (event.type) {
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::KeyPressed:

					game.processEvents(event.key.code);

					break;
				}


			} // Event loop

			fElapsedTime = timer.getElapsedTime().asSeconds();
			if (fElapsedTime > fFrameTime)
			{
				gameView.setRotation(game.getRot()); //rotates the view
				game.getWorld()->Step(fElapsedTime, 7, 5);
				game.update(fFrameTime);
				timer.restart();
			}

			gameView.setCenter(game.getBall()->getBallPos().x, game.getBall()->getBallPos().y);  //sets the view on the ball

			window.clear();

		    window.setView(gameView);

			window.draw(game);     //draws the game to the window


			window.setView(miniView);

			window.draw(RS2);  //draws the rects
            window.draw(RS);
			window.draw(game);      //draws the mini view
			window.draw(game.getUI().getTextLives());     //gets the text
			window.draw(game.getUI().getTextTime());


			window.display(); 


		}

		if (game.getGameOver())   //when game is over
		{
			window.close();
			sf::RenderWindow windowTwo(sf::VideoMode(960, 720), "Box2DGame"); // creates the second window
			sf::Event eventTwo;

			sf::Texture temp;
			sf::Texture temp2;   //sets the texture

			temp = textureManager->instance()->getTexture("Space");
			temp2 = textureManager->instance()->getTexture("OwlTwo");

			sf::RectangleShape RSThree(sf::Vector2f(960, 720));
			sf::RectangleShape RSFour(sf::Vector2f(490, 560));
			RSFour.setPosition(520, 300);
			RSThree.setTexture(&temp);
			RSFour.setTexture(&temp2);

			sf::RectangleShape RS5(sf::Vector2f(636.5f, 90.5f));    
			RS5.setFillColor(sf::Color(1, 1, 1));
			RS5.setPosition(0, 100);

			while (windowTwo.isOpen())
			{
				while (windowTwo.pollEvent(eventTwo))
				{
					switch (eventTwo.type) {
					case sf::Event::Closed:
						windowTwo.close();
						break;
					}
				}
				
				windowTwo.clear();
				
				windowTwo.draw(RSThree);
				windowTwo.draw(RSFour);
				windowTwo.draw(RS5);
				windowTwo.draw(game.getUI().getTextScore());  //draws eveything in the second window

				windowTwo.display();

			}

		}

	
	
	
}

