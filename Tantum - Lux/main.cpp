#include <iostream>
#include <SFML/Graphics.hpp>


int main()
{
	sf::RenderWindow rWindow(sf::VideoMode(900, 900), "Tantum - Lux");

	sf::Event event;
	sf::Clock clock;
	sf::Time dt;

	while (rWindow.isOpen())
	{
		while (rWindow.pollEvent(event))
		{

		}
		dt = clock.restart();


		rWindow.display();
		rWindow.clear();
	}
	return 0;
}