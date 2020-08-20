#include "Player.h" 

Player::Player() {
	pos_x = 45.f;
	pos_y = 45.f; 
	dx = 0;
	dy = 0;
	playerModel = new sf::CircleShape(10.f); 
	playerModel->setOrigin(10.f/2, 10.f/2); 
	playerModel->setFillColor(sf::Color::White); 
	playerModel->setPosition(pos_x, pos_y); 
}

Player::~Player() {
	delete playerModel; 
}