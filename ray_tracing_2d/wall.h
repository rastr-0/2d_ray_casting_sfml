#pragma once
#include "globals.h"
class wall {
private:
	sf::Vector2f begin;
	sf::Vector2f end;
public:
	wall();
	void set_begin(sf::Vector2f begin);
	void set_end(sf::Vector2f end);
	sf::Vector2f get_begin();
	sf::Vector2f get_end();
};