#include "wall.h"
sf::Vector2f wall::get_begin() {
	return this->begin;
}
sf::Vector2f wall::get_end() {
	return this->end;
}
wall::wall() {
	this->begin = { 0, 0 };
	this->end = { 0, 0 };
}
void wall::set_begin(sf::Vector2f begin) {
	this->begin = begin;
}
void wall::set_end(sf::Vector2f end) {
	this->end = end;
}
