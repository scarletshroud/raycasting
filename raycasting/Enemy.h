#ifndef ENEMY_H
#define ENEMY_H

#define _USE_MATH_DEFINES

#include <math.h>

#include "SFML/Graphics.hpp"
#include "Map.h"

class Player;

class Enemy {
public:
	Enemy(Map&, Player&);
	~Enemy();

	void update(sf::RenderWindow&, float);
	void findPath(sf::Vector2f); 

	bool isPlayerVisible(sf::Vector2f) const;
	bool checkCollisionWithMap() const;

	float size() const;
	sf::Vector2f position() const;
	static sf::CircleShape& getEnemyModel(); 

private:
	const float SPEED = 0.01f;
	const float ENEMY_SIZE = 10.f;
	const float VISIBILITY_RANGE = 200.f;

	float pos_x;
	float pos_y;
	float dx;
	float dy;

	float health; 

	Map& map;
	Player& player;

	static sf::CircleShape enemyModel;
};

#endif 
