#pragma once

#include <SFML/Graphics.hpp>

#include "map.h"
#include "Player.h"

class Renderer {
private:
	sf::RenderWindow *window; 
	Map* map;
	Player* player;

public:
	Renderer(sf::RenderWindow &window);
	~Renderer();

	void render(); 
};