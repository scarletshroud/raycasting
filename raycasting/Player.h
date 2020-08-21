#pragma once

#include "SFML/Graphics.hpp"
#include "Map.h"

class Player {
private:
	const float SPEED = 0.1f; 
	const double PI = 3.141592653589793;
	float pos_x;
	float pos_y; 
	float dx;
	float dy; 
	double sightAngle; 

	std::vector<sf::VertexArray*> sightLines;

	sf::CircleShape* playerModel; 
	Map* map;

	bool handleEvent();
	void lookAt(sf::RenderWindow& window); 

public:
	Player(Map* map);
	~Player();

	void update(sf::RenderWindow& window, float time);

	sf::CircleShape* getPlayerModel();
	std::vector<sf::VertexArray*>& getSightLines();
};