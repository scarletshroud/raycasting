#include "Player.h" 
#include <iostream>

Player::Player(Map* map) {
	pos_x = 65.f;
	pos_y = 65.f; 
	dx = 0;
	dy = 0;
	sightAngle = 0;
	this->map = map;
	playerModel = new sf::CircleShape(PLAYER_SIZE); 
	playerModel->setOrigin(PLAYER_SIZE/2, PLAYER_SIZE/2); 
	playerModel->setFillColor(sf::Color::White); 
	playerModel->setPosition(pos_x, pos_y); 
}

Player::~Player() {
	delete playerModel; 
}

bool Player::handleEvent() {
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W))) {
		dy = -SPEED; 
		return true;
	}

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A))) {
		dx = -SPEED;
		return true;
	}

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::S))) {
		dy = SPEED;
		return true;
	}

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D))) {
		dx = SPEED;
		return true;
	}

	return false;
}

void Player::lookAt(sf::RenderWindow& window) {
	/* for (const auto& sightLine : sightLines) { //throws exeption
		 delete sightLine;
	 } */

	sightLines.clear();

	sf::Vector2i cursorPos = sf::Mouse::getPosition(window);
	float cursor_dx = cursorPos.x - pos_x;
	float cursor_dy = cursorPos.y - pos_y;
	double sightAngle = (atan2(cursor_dy, cursor_dx)) - PI / 6;

	float i = 0;

	while (i <= PI / 3) {
		i += 0.01f;

		float end_pointX = 0;
		float end_pointY = 0;

		for (float distance = 0; distance < 300; distance += 1) {
			end_pointX = pos_x + distance * cos(sightAngle);
			end_pointY = pos_y + distance * sin(sightAngle);
			if (map->checkIntersection(end_pointX, end_pointY)) {
				break;
			}
		}

		sf::VertexArray* line = new sf::VertexArray(sf::Lines, 2);
		(*line)[0].position = sf::Vector2f(pos_x, pos_y);
		(*line)[0].color = sf::Color::Blue;
		(*line)[1].position = sf::Vector2f(end_pointX, end_pointY);
		(*line)[1].color = sf::Color::Red;

		sightLines.push_back(line);
		sightAngle += 0.01;
	}
}

void Player::drawWalls() {

}

void Player::update(sf::RenderWindow& window, float time) {
	if (handleEvent()) {
		if (!checkCollision()) {
			pos_x += dx * time;
			pos_y += dy * time;
			playerModel->setPosition(pos_x, pos_y);
		}
		dx = 0;
		dy = 0;
	}

	lookAt(window);
}

bool Player::checkCollision() {
	auto signX = std::copysign(1, dx);
	auto signY = std::copysign(1, dy); 
	if (!map->checkIntersection(pos_x + PLAYER_SIZE / 2 * signX, pos_y + PLAYER_SIZE / 2 * signY)) {
		return false;
	}
	return true;
}

sf::CircleShape* Player::getPlayerModel() {
	return playerModel;
}

std::vector<sf::VertexArray*>& Player::getSightLines() {
	return sightLines;
}