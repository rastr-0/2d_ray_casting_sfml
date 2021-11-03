#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>
#include "globals.h"
int main() {
	srand(time(0));
	sf::RenderWindow window(sf::VideoMode(640, 480), "ray_tracing");
	// creating walls
	std::vector<wall> walls;
	walls.resize(3);
	for (int i = 0; i < 3; i++) {
		sf::Vector2f temp;
		// creating two random points of begin
		temp.x = rand() % window.getSize().x;
		temp.y = rand() % window.getSize().y;
		walls[i].set_begin(temp);
		//creating two random points of end
		temp.x = rand() % window.getSize().x;
		temp.y = rand() % window.getSize().y;
		walls[i].set_end(temp);
	}
	// vector of lines, I need this for drawing on the screen
	std::vector<sf::VertexArray> lines;
	lines.resize(3);
	for (int i = 0; i < 3; i++) {
		lines[i].setPrimitiveType(sf::LinesStrip);
		lines[i].resize(2);
		lines[i][0].position = walls[i].get_begin();
		lines[i][1].position = walls[i].get_end();
	}
	// creating rays
	std::vector<ray> rays;
	const float step = 1.f / count_of_rays;
	for (double i = 0; i < two_pi; i += step) {
		const float x = sin(i);
		const float y = cos(i);
		rays.push_back(ray(x, y));
	}
	// ray_line is a line, which will represent ray
	sf::VertexArray ray_line(sf::Lines, 2);
	ray_line[0].color = sf::Color(80, 206, 139, 180);
	ray_line[1].color = sf::Color(80, 206, 139, 180);
	// vector2f, which will contain mouse position
	sf::Vector2f m_mouse_position;
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		m_mouse_position = sf::Vector2f(sf::Mouse::getPosition(window));
		// set the start for the ray
		ray_line[0].position = m_mouse_position;

		window.clear();
		// create nested loop for checking all rays with each wall
		for (int i = 0; i < rays.size(); i++) {
			rays[i].reset(m_mouse_position);
			for (int j = 0; j < walls.size(); j++) {
				// if we find intersection, than we will initialize end point of the ray
				rays[i].intersection(walls[j].get_begin(), walls[j].get_end(), m_mouse_position);
			}
			ray_line[1].position = rays[i].end;
			// draw ray
			window.draw(ray_line);
		}
		// draw walls
		for (int i = 0; i < 3; i++) {
			window.draw(lines[i]);
		}
		window.display();
	}
}