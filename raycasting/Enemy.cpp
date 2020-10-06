#include "Enemy.h"
#include "Player.h"
#include "Map.h"

sf::CircleShape Enemy::enemyModel;

Enemy::Enemy(Map& map, Player& player) :
	pos_x(100.f),
	pos_y(100.f),
	dx(0),
	dy(0),
	health(100),
	map(map),
	player(player)
{
	enemyModel = sf::CircleShape(ENEMY_SIZE);
	enemyModel.setOrigin(ENEMY_SIZE / 2, ENEMY_SIZE / 2);
	enemyModel.setFillColor(sf::Color::Red);
	enemyModel.setPosition(pos_x, pos_y);
}

Enemy::~Enemy() {
}

void Enemy::update(sf::RenderWindow& window, float time) {

	if (isPlayerVisible(player.position())) {
		if (!checkCollisionWithMap()) {
			findPath(player.position());
			pos_x += dx * time; 
			pos_y += dy * time;
			enemyModel.setPosition(pos_x, pos_y);
		}
	}

	dx = 0;
	dy = 0; 

}

void Enemy::findPath(sf::Vector2f destPoint) {
	float sightAngle = float((atan2(destPoint.y - pos_y, destPoint.x - pos_x)) - M_PI / 6);
	dx = double(cos(sightAngle)) * SPEED;
	dy = double(sin(sightAngle)) * SPEED;
}

bool Enemy::isPlayerVisible(sf::Vector2f destPoint) const {
	float distance = sqrt((destPoint.x - pos_x) * (destPoint.x - pos_x) + (destPoint.y - pos_y) * (destPoint.y - pos_y));

	return distance < VISIBILITY_RANGE;
	
}

bool Enemy::checkCollisionWithMap() const {
	auto signX = std::copysign(1, dx);
	auto signY = std::copysign(1, dy);

	return map.checkIntersection(pos_x + ENEMY_SIZE / 2 * signX, pos_y + ENEMY_SIZE / 2 * signY);
}

float Enemy::size() const {
	return ENEMY_SIZE;
}

sf::Vector2f Enemy::position() const {
	return sf::Vector2f(pos_x, pos_y);
}

sf::CircleShape& Enemy::getEnemyModel() {
	return enemyModel;
}

