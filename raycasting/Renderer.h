#ifndef RENDERER_H
#define RENDERER_H

#include <SFML/Graphics.hpp>

#include "Map.h"
#include "Player.h"
#include "Enemy.h"

class Renderer {
public:
	Renderer(sf::RenderWindow&);
	~Renderer();

	void update(float);
	void render(); 

private:
	sf::RenderWindow& window;
	Map map;
	Player player;
	Enemy enemy;
};

#endif