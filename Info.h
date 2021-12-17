#pragma once
#include <SFML/Graphics.hpp>
#include "MenuComponentStyle.h"


class Info : public sf::Drawable
{
	sf::Text text;
	sf::RectangleShape hitbox;

	MenuComponentStyle style;

public:

	Info(sf::Vector2f const& pos,sf::Vector2f const& size, std::string const& content,MenuComponentStyle const& style_);
	
	void draw(sf::RenderTarget & target,sf::RenderStates states)const;
	void setContent(std::string const& content);
	void setColorText(sf::Color const& color);

};