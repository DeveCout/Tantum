#include "Info.h"
#include <SFML/Graphics.hpp>*

extern sf::Font fontClassic;

Info::Info(sf::Vector2f const& pos, sf::Vector2f const& size, std::string const& content, MenuComponentStyle const& style_):style(style_)
{
	hitbox = sf::RectangleShape(size);
	hitbox.setPosition(pos);
	hitbox.setFillColor(style.background);

	text = sf::Text(content, fontClassic);

	sf::Vector2f hitboxCenter = hitbox.getPosition() + sf::Vector2f(hitbox.getLocalBounds().width / 2, hitbox.getLocalBounds().height / 2);
	text.setPosition(hitboxCenter - sf::Vector2f(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2));

	text.setString(content);
}

void Info::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(hitbox);
	target.draw(text);
}

void Info::setContent(std::string const& content)
{
	text.setString(content);
}

void Info::setColorText(sf::Color const& color)
{
	text.setFillColor(color);
}
