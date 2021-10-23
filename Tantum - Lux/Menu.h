#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Menu : public sf::Drawable
{
	std::vector<sf::RectangleShape> buttons;




public :

	void draw(sf::RenderTarget & target,sf::RenderStates states)const;


};

