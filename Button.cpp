#include "Button.h"
#include <iostream>

extern sf::Font fontClassic;

Button::Button(sf::Vector2f const& pos, sf::Vector2f const& size, e_button_action const& action_,std::string const& content, MenuComponentStyle const& MenuComponentStyle_) :
	buttonStyle(MenuComponentStyle_),buttonStyleOver(MenuComponentStyle(MenuComponentStyle_)),buttonStyleClick(MenuComponentStyle(MenuComponentStyle_)),
	action(action_)
{
	hitbox = sf::RectangleShape(size);
	
	hitbox.setFillColor(buttonStyle.background);
	hitbox.setPosition(pos);

	sf::Vector2f hitboxCenter = hitbox.getPosition() + sf::Vector2f(hitbox.getLocalBounds().width/2, hitbox.getLocalBounds().height/2);
	text = sf::Text(content,fontClassic);

	text.setPosition(hitboxCenter - sf::Vector2f(text.getLocalBounds().width/2, text.getLocalBounds().height / 2));
}

e_button_action Button::click(sf::Vector2f const& posClick) const
{
	if (posClick.x > hitbox.getPosition().x && posClick.x < hitbox.getPosition().x + hitbox.getSize().x)
	{
		if (posClick.y > hitbox.getPosition().y && posClick.y < hitbox.getPosition().y + hitbox.getSize().y)
		{
			return action;
		}
	}
	return NO_ACTION;
}

void Button::update(sf::Time const& dt, sf::Vector2f mousePos)
{
	if (click(mousePos) != NO_ACTION)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			state = CLICK;
			hitbox.setFillColor(buttonStyleClick.background);
		}
		else
		{
			state = OVER;
			hitbox.setFillColor(buttonStyleOver.background);
		}
	}
	else
	{
		state = DEFAULT;
		hitbox.setFillColor(buttonStyle.background);
	}
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(hitbox);
	if (state == OVER || state == CLICK)
	{
		sf::VertexArray lighting(sf::PrimitiveType::Quads, 4);
		lighting[0].position = hitbox.getPoint(0) + hitbox.getPosition();
		lighting[1].position = hitbox.getPoint(1) + hitbox.getPosition();
		lighting[2].position = hitbox.getPoint(2) + hitbox.getPosition();
		lighting[3].position = hitbox.getPoint(3) + hitbox.getPosition();


		lighting[0].color = sf::Color(0, 0, 0, 0);
		lighting[1].color = sf::Color(0, 0, 0, 0);
		lighting[2].color = sf::Color(255, 255, 255, 200);
		lighting[3].color = sf::Color(255, 255, 255, 200);

		target.draw(lighting);
	}
	target.draw(text);
}

void Button::setColorText(sf::Color const& color)
{
	text.setFillColor(color);
}

void Button::setMenuComponentStyle(MenuComponentStyle const& style)
{
	buttonStyle = style;
}

void Button::setMenuComponentStyleOver(MenuComponentStyle const& style)
{
	buttonStyleOver = style;
}

void Button::setMenuComponentStyleClick(MenuComponentStyle const& style)
{
	buttonStyleClick = style;
}

void Button::setContent(std::string const& string)
{
	text.setString(string);
}
