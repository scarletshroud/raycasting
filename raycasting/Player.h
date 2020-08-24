#pragma once

#include "SFML/Graphics.hpp"
#include "Map.h"

class Player {
private:
	const float SPEED = 0.1f; 
	const double PI = 3.141592653589793;
	const float PLAYER_SIZE = 10.f;
	float pos_x;
	float pos_y; 
	float dx;
	float dy; 
	double sightAngle; 

	std::vector<sf::VertexArray*> sightLines;
	std::vector<sf::VertexArray*> walls; 

	sf::CircleShape* playerModel; 
	Map* map;

	bool handleEvent();
	void lookAt(sf::RenderWindow& window); 
	void drawWalls(double sightAngle); 

public:
	Player(Map* map);
	~Player();

	void update(sf::RenderWindow& window, float time);
	bool checkCollision();

	sf::CircleShape* getPlayerModel();
	std::vector<sf::VertexArray*>& getSightLines();
	std::vector<sf::VertexArray*>& getWalls();
};