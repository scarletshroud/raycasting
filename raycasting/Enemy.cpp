#include "Enemy.h"

Enemy::Enemy() {

	pos_x = 100.f;
	pos_y = 100.f;
	dx = 0;
	dy = 0;

	enemyModel = new sf::CircleShape(ENEMY_SIZE);
	enemyModel->setOrigin(ENEMY_SIZE / 2, ENEMY_SIZE / 2);
	enemyModel->setFillColor(sf::Color::Red);
	enemyModel->setPosition(pos_x, pos_y);
}

Enemy::~Enemy() {
	delete enemyModel;
}

void Enemy::update() {

}

sf::CircleShape* Enemy::getEnemyModel() {
	return enemyModel;
}

