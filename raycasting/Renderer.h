#pragma once

#include <SFML/Graphics.hpp>

#include "Map.h"
#include "Player.h"

class Renderer {
private:
	sf::RenderWindow *window; 
	Map* map;
	Player* player;

public:
	Renderer(sf::RenderWindow& window);
	~Renderer();

	void update(float time);
	void render(); 
};