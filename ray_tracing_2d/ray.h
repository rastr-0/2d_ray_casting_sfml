#pragma once
#include "globals.h"
class ray {
private:
	sf::Vector2f relative_end;
public:
	sf::Vector2f end;
	ray();
	ray(float x, float y);
	void intersection(sf::Vector2f wall1, sf::Vector2f wall2, sf::Vector2f& m_mouse_position);
	void reset(sf::Vector2f& m_mouse_position);
};