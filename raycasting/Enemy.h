#ifndef ENEMY_H
#define ENEMY_H

#include "SFML/Graphics.hpp"

class Enemy {
private:
	const float SPEED = 0.01f; 
	const float ENEMY_SIZE = 10.f; 
	float pos_x; 
	float pos_y;
	float dx; 
	float dy;

	sf::CircleShape* enemyModel;
	
public:
	Enemy();
	~Enemy();

	void update(); 
	sf::CircleShape* getEnemyModel(); 
};

#endif 
