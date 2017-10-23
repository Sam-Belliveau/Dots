#include <SFML/Graphics.hpp>
#include "Partical.h"
#include <stdlib.h>
#include <ctime>

int main()
{
	const float winWidth = 1280;
	const float winHeight = 720;

	const int AMOUNT = 2560; // Partical Count

	/* Min and Max Cordinates*/
	sf::Vector2f MAX_CORD = sf::Vector2f(winWidth, winHeight);
	sf::Vector2f MIN_CORD = sf::Vector2f(0.0f, 0.0f);

	sf::Color COLOR(192, 192, 192); // Partical Color

	sf::VertexArray VERTEX = sf::VertexArray(sf::Points, AMOUNT); // Drawable Refrence

	Partical dots[AMOUNT]; // Updateable Partical

	srand(time(NULL));

	for (int i = 0; i < AMOUNT; i++)
	{

		dots[i].Reset(sf::Vector2f(
			(float)((rand() % (int)(MAX_CORD.x - MIN_CORD.x)) + (int)MIN_CORD.x),
			(float)((rand() % (int)(MAX_CORD.y - MIN_CORD.y)) + (int)MIN_CORD.y)),
			COLOR); // Makes Partical

		VERTEX[i] = dots[i].PARTICAL; // Makes Drawable Refrence
		//printf("DOT ID: (%i/%i) POS: (%i, %i)\n", i, AMOUNT, (int)dots[i].PARTICAL.position.x, (int)dots[i].PARTICAL.position.y);
	}

	sf::RenderWindow window(sf::VideoMode((int) winWidth, (int) winHeight), "Particals", sf::Style::Close);

	window.setFramerateLimit(60);

	while (window.isOpen())
	{

		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			}
		}

		for (int i = 0; i < AMOUNT; i++)
		{
			dots[i].update(sf::Mouse::isButtonPressed(sf::Mouse::Left), sf::Mouse::getPosition(window), MAX_CORD, MIN_CORD);
			VERTEX[i] = dots[i].PARTICAL;
		}

		window.clear(sf::Color(16,16,16));
		window.draw(VERTEX);
		window.display();
	}

	return 0;
}