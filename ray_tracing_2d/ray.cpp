#include "globals.h"
#include "ray.h"
ray::ray() {};
// set end point for the ray
ray::ray(float x, float y) {
	// I multiply vector2f by 2000.f just for creating long rays, wich will be in all situation out of the screen
	// you can experiment and change 2000.f for 200.f, rays will be shorter
	this->relative_end = sf::Vector2f(x, y) * 2000.f; 
}
void ray::reset(sf::Vector2f& m_mouse_position) {
	this->end = m_mouse_position + this->relative_end;
}
// formulas, which I use in this function you can find in Wiki(Line-line intersection) article
void ray::intersection(sf::Vector2f p3, sf::Vector2f p4, sf::Vector2f& m_mouse_position) {
	const sf::Vector2f p1 = m_mouse_position;
	const sf::Vector2f p2 = this->end;

	const float den = (p1.x - p2.x) * (p3.y - p4.y) - (p1.y - p2.y) * (p3.x - p4.x);

	if (den == 0)
		return;

	const float t = ((p1.x - p3.x) * (p3.y - p4.y) - (p1.y - p3.y) * (p3.x - p4.x)) / den;
	const float u = -((p1.x - p2.x) * (p1.y - p3.y) - (p1.y - p2.y) * (p1.x - p3.x)) / den;

	if (t > 0 && t < 1 && u > 0 && u < 1)
	{
		this->end.x = p1.x + t * (p2.x - p1.x);
		this->end.y = p1.y + t * (p2.y - p1.y);
	}
}
