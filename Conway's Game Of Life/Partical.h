#include <SFML/Graphics.hpp>

class Partical
{
public:
	Partical(sf::Vector2f pos, sf::Color color);
	Partical();
	void Reset(sf::Vector2f pos, sf::Color color);

	void update(bool useMouse, sf::Vector2i mousePos, sf::Vector2f MAX_CORD, sf::Vector2f MIN_CORD);

public:
	const float SPACE = 128;
	sf::Vector2f VEL = sf::Vector2f(0.0f,0.0f);
	sf::Vertex PARTICAL;
};

