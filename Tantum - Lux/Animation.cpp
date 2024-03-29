#include "Animation.h"
#include "Spritesheet.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Animation::Animation() : sprs(NULL), duration(0), timer(0), scaleX(1), scaleY(1)
{
}

Animation::Animation(Spritesheet* sprs_, float duration_, float scaleX_, float scaleY_) : sprs(sprs_), duration(duration_),timer(0),scaleX(scaleX_), scaleY(scaleY_)
{
	
}

void Animation::refresh(sf::Time dt)
{
	timer += dt.asSeconds();
	if (timer >= duration)
	{
		timer = 0;
	}
}

sf::Sprite Animation::getSprite() const
{
	sf::Sprite spr = sprs->getSprite((int)(sprs->getTotalSprite() * timer / duration));
	spr.setScale(scaleX,scaleY);
	return spr;
}

void Animation::beDraw(sf::RenderWindow& rWindow)
{
	rWindow.draw(getSprite());
}
