#ifndef RENDERER_H
#define RENDERER_H

#include <SFML/Graphics.hpp>

#include "Map.h"
#include "Player.h"
#include "Enemy.h"

class Renderer {
private:
	sf::RenderWindow *window; 
	Map* map;
	Player* player;
	Enemy* enemy; 

public:
	Renderer(sf::RenderWindow& window);
	~Renderer();

	void update(float time);
	void render(); 
};

#endif