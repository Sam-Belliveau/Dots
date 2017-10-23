#include "Partical.h"


Partical::Partical(sf::Vector2f pos, sf::Color color)
{
	PARTICAL = sf::Vertex(pos, color);
}

void Partical::Reset(sf::Vector2f pos, sf::Color color)
{
	PARTICAL.position.x = pos.x;
	PARTICAL.position.y = pos.y;
	PARTICAL.color = color;
}

Partical::Partical(){
	PARTICAL = sf::Vertex(sf::Vector2f(0,0), sf::Color::White);
}

void Partical::update(bool useMouse, sf::Vector2i mousePos, sf::Vector2f MAX_CORD, sf::Vector2f MIN_CORD)
{
	if (useMouse)
	{
		if (abs(PARTICAL.position.x - (float)mousePos.x) < SPACE &&
			abs(PARTICAL.position.y - (float)mousePos.y) < SPACE)
		{
			VEL.x -= (PARTICAL.position.x - (float)mousePos.x);

			VEL.y -= (PARTICAL.position.y - (float)mousePos.y);
		}
	}
	/* Slow Down Particals */
	VEL.x -= VEL.x / (1 << 10);
	VEL.y -= VEL.y / (1 << 10);

	/*Checking For Walls*/
	if (PARTICAL.position.x < MIN_CORD.x) // Left Wall
	{
		PARTICAL.position.x = MIN_CORD.x;
		VEL.x = 0 - VEL.x;
	}
	if (PARTICAL.position.x > MAX_CORD.x) // Right Wall
	{
		PARTICAL.position.x = MAX_CORD.x;
		VEL.x = 0 - VEL.x;
	}

	if (PARTICAL.position.y < MIN_CORD.y) // Top Wall
	{
		PARTICAL.position.y = MIN_CORD.y;
		VEL.y = 0 - VEL.y;
	}
	if (PARTICAL.position.y > MAX_CORD.y) // Bottom Wall
	{
		PARTICAL.position.y = MAX_CORD.y;
		VEL.y = 0 - VEL.y;
	}

	/* Updating Position */
	PARTICAL.position.x += VEL.x / (1 << 8);
	PARTICAL.position.y += VEL.y / (1 << 8);
}
