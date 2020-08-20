#pragma once

#include "SFML/Graphics.hpp"

class Player {
private:
	float pos_x;
	float pos_y; 
	int dx;
	int dy; 

	sf::CircleShape* playerModel; 

public:
	Player();
	~Player();

	sf::CircleShape* getPlayerModel() {
		return playerModel;
	}
};