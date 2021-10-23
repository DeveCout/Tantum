#include "ParticleSystem.h"

ParticleSystem::ParticleSystem():
	vertices(sf::PrimitiveType::Triangles, 0),
	count(0),
	centers(0)
{
}

ParticleSystem::ParticleSystem(unsigned int const count_) :
	vertices(sf::PrimitiveType::Triangles, count*3),
	count(count_),
	centers(count_)
{
}

void ParticleSystem::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(vertices);
}

void ParticleSystem::rotate(unsigned int index, float angle)
{
	angle *= 3.1415 / 180;

	vertices[index].color = sf::Color::Black;
	vertices[index+1].color = sf::Color::Black;
	vertices[index+2].color = sf::Color::Black;
	float xM = vertices[index].position.x - centers[index].x;
	float yM = vertices[index].position.y - centers[index].y;
	float x = xM * cos(angle) + yM * sin(angle) + centers[index].x;
	float y = -xM * sin(angle) + yM * cos(angle) + centers[index].y;
	vertices[index].position = sf::Vector2f(x, y);

	xM = vertices[index+1].position.x - centers[index].x;
	yM = vertices[index+1].position.y - centers[index].y;
	x = xM * cos(angle) + yM * sin(angle) + centers[index].x;
	y = -xM * sin(angle) + yM * cos(angle) + centers[index].y;
	vertices[index].position = sf::Vector2f(x, y);

	xM = vertices[index+2].position.x - centers[index].x;
	yM = vertices[index+2].position.y - centers[index].y;
	x = xM * cos(angle) + yM * sin(angle) + centers[index].x;
	y = -xM * sin(angle) + yM * cos(angle) + centers[index].y;
	vertices[index].position = sf::Vector2f(x, y);

}
