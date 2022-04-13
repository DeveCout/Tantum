#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class ParticleSystem : public sf::Drawable
{
protected:

	unsigned int count;
	sf::VertexArray vertices;
	std::vector<sf::Vector2f> centers;

public :

	ParticleSystem();
	ParticleSystem(unsigned int const count);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void reset(std::size_t index) = 0;
	virtual void update(sf::Time dt) = 0;
	virtual void rotate(unsigned int index, float angle);
};