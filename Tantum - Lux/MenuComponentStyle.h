#pragma once
#include <SFML/Graphics.hpp>

struct MenuComponentStyle {

	sf::Color background;


	MenuComponentStyle(sf::Color background_) {
		background = background_;
	}
};