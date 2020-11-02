#include <iostream>

#include "Player.h"
#include "Enemy.h"

sf::CircleShape Player::playerModel;

Player::Player(Map& map, Enemy& enemy) : 
	pos_x(65.f), 
    pos_y(65.f), 
    dx(0), 
    dy(0), 
    sightAngle(0),
	health(100),
    map(map), 
	enemy(enemy)
{
	playerModel = sf::CircleShape(PLAYER_SIZE); 
	playerModel.setOrigin(PLAYER_SIZE/2, PLAYER_SIZE/2); 
	playerModel.setFillColor(sf::Color::White); 
	playerModel.setPosition(pos_x, pos_y); 
}

Player::~Player() {
}

bool Player::handleEvent() {

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W))) {

		dy = float(sin(sightAngle - M_PI / 6) * SPEED); 
		dx = float(cos(sightAngle - M_PI / 6) * SPEED);

		return true;
	}

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A))) {

		dy = float(sin(sightAngle - M_PI / 6 - M_PI_2) * SPEED);
		dx = float(cos(sightAngle - M_PI / 6 - M_PI_2) * SPEED);

		return true;
	}

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::S))) {

		dy = float(-sin(sightAngle - M_PI / 6) * SPEED);
		dx = float(-cos(sightAngle - M_PI / 6) * SPEED);

		return true;
	}

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D))) {

		dy = float(sin(sightAngle - M_PI / 6 + M_PI_2) * SPEED);
		dx = float(cos(sightAngle - M_PI / 6 + M_PI_2) * SPEED);

		return true;
	}

	return false;
}

void Player::lookAt(sf::RenderWindow& window)
{
	sf::Vector2i cursorPos = sf::Mouse::getPosition(window);
	sf::Vector3i color;

	const size_t LAMBDA = 40000;
	const size_t WALL_START_Y = 550;

	float cursor_dx = cursorPos.x - pos_x;
	float cursor_dy = cursorPos.y - pos_y;
	float i = 0; 

	sightAngle = (atan2(cursor_dy, cursor_dx)) - M_PI / 6;

	sightLines.clear();
	walls.clear();

	while (i <= M_PI / 3) {

		i += 0.0020453f;
		//i += 1.2f;

		bool reachedWall = false;

		float end_pointX = 0;
		float end_pointY = 0;
		float cosAngle = (float) (cos(sightAngle));
		float sinAngle = (float) (sin(sightAngle));

		for (float distance = 0; distance < VISIBILITY_RANGE; distance += 1) {

			end_pointX = pos_x + distance * cosAngle;
			end_pointY = pos_y + distance * sinAngle;

			if (map.checkIntersection(end_pointX, end_pointY)) {
				reachedWall = true;
				color = sf::Vector3i(0, 255, 255);
				break;
			}

			if (checkCollisionWithEnemy(end_pointX, end_pointY)) {
				reachedWall = true;
				color = sf::Vector3i(220, 20, 60);
				break;
			}
		}

		sf::VertexArray line = sf::VertexArray(sf::Lines, 2);

		line[0].position = sf::Vector2f(pos_x, pos_y);
		line[1].position = sf::Vector2f(end_pointX, end_pointY);

		line[0].color = sf::Color::Blue;
		line[1].color = sf::Color::Red;

		sightLines.push_back(line);

		if (reachedWall) {

			float offsetX = end_pointX - pos_x;
			float offsetY = end_pointY - pos_y;
			float distance = sqrt(offsetX * offsetX + offsetY * offsetY);
			float wall_length = LAMBDA / distance;

		    sf::Sprite wallSprite = map.getWallSprite(end_pointX, end_pointY);
			wallSprite.setPosition(500 + i * 1000, WALL_START_Y);
			wallSprite.scale(1, -1 * wall_length / 128);
		//	wallSprite.setTextureRect(sf::IntRect(0, 0, 1, wallSprite.getTextureRect().height));

		/*	sf::VertexArray wall = sf::VertexArray(sf::Lines, 2);

			wall[0].position = sf::Vector2f(500 + i * 1000, WALL_START_Y);
			wall[1].position = sf::Vector2f(500 + i * 1000, WALL_START_Y - wall_length);

	ó		wall[0].texCoords = sf::Vector2f(500 + i * 1000, WALL_START_Y);
			wall[1].texCoords = sf::Vector2f(500 + i * 1000, WALL_START_Y - wall_length);

			wall[0].color = sf::Color(color.x, color.y, color.z, 255 - distance / 1.5);
			wall[1].color = sf::Color(color.x, color.y, color.z, 255 - distance / 1.5); */

			walls.push_back(wallSprite);
		}

		sightAngle += 0.0020453f;
	    //sightAngle += 1.2f;
	}
}

void Player::drawWalls(double sightAngle) {
	 
}

void Player::update(sf::RenderWindow& window, float time) {

	if (handleEvent()) {

		if (!checkCollisionWithMap()) {
			pos_x += dx * time;
			pos_y += dy * time;
			playerModel.setPosition(pos_x, pos_y);
		}

		dx = 0;
		dy = 0;
	}

	lookAt(window);
	drawWalls(sightAngle);
}
	
bool Player::checkCollisionWithMap() {

	auto signX = std::copysign(1, dx);
	auto signY = std::copysign(1, dy); 
	
	return map.checkIntersection((float) (pos_x + PLAYER_SIZE / 2 * signX), (float) (pos_y + PLAYER_SIZE / 2 * signY));
}

bool Player::checkCollisionWithEnemy(float x, float y) {

	if (x >= enemy.position().x - enemy.size() / 2 && x <= enemy.position().x + enemy.size() / 2) {
		if (y >= enemy.position().y - enemy.size() / 2 && y <= enemy.position().y + enemy.size() / 2) {
			return true;
		}
	}

	return false;
}

sf::Vector2f Player::position() const {
	return sf::Vector2f(pos_x, pos_y);
}

sf::CircleShape& Player::getPlayerModel() {
	return playerModel;
}

const std::vector<sf::VertexArray>& Player::getSightLines() const {
	return sightLines;
}

const std::vector<sf::Sprite>& Player::getWalls() const {
	return walls;
}