#ifndef PLAYER_H
#define PLAYER_H

#define _USE_MATH_DEFINES

#include <math.h>
#include <map>

#include "SFML/Graphics.hpp"
#include "Map.h"

class Enemy;

class Player {
public:
	Player(Map&, Enemy&);
	~Player();

	void update(sf::RenderWindow&, float);

	bool checkCollisionWithMap();
	bool checkCollisionWithEnemy(float, float);

    sf::Vector2f position() const;
	static sf::CircleShape& getPlayerModel();

	const std::vector<sf::VertexArray>& getSightLines() const;
	const std::vector<sf::Sprite>& getWalls() const;

private:
	const float SPEED = 0.05f;
	const float PLAYER_SIZE = 10.f;
	const float VISIBILITY_RANGE = 300.f;

	float pos_x;
	float pos_y;
	float dx;
	float dy;

	float sightAngle;

	float health; 

	Map& map;
	Enemy& enemy;

	void lookAt(sf::RenderWindow&);
	void drawWalls(double);

	bool handleEvent();

	std::vector<sf::VertexArray> sightLines;
	//std::vector<sf::VertexArray> walls;
	std::vector<sf::Sprite> walls;
	static sf::CircleShape playerModel;
};

#endif 