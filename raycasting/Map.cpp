#include "map.h"
#include <iostream>
#include <cmath>

const char* Map::p_markup =
							"111111111111111"
							"1             1"
							"1      11111  1"
							"1             1"
							"1        111111"
							"1             1"
							"1     111     1"
							"1       1     1"
							"1   1   1     1"
							"1   1   1  1111"
							"1       1     1"
							"1       1     1"
							"1       1     1"
							"1             1"
							"111111111111111";

Map::Map() {

	wallTexture.loadFromFile("textures/simple_wall.png");

	sf::Sprite wallSprite(wallTexture);

	textures = {
		{'1', wallSprite}
	};
	 
	size_t j = 0;

	for (size_t i = 0; i < (size_t) (MAP_HEIGHT * MAP_WIDTH); ++i) {

		if (p_markup[i] == '1') {
			sf::RectangleShape rectangle = sf::RectangleShape(sf::Vector2f(CELL_SIZE, CELL_SIZE));

			rectangle.setFillColor(sf::Color::Cyan);
			rectangle.setOrigin(CELL_SIZE / 2, CELL_SIZE / 2);
			rectangle.setPosition(CELL_SIZE * (i % MAP_WIDTH + 1), CELL_SIZE * (j + 1));

			walls.push_back(rectangle);
		}

		if (i % MAP_HEIGHT == 14) {
			j++;
		}

	}
}

Map::~Map() {
}

size_t Map::width() const {
	return MAP_WIDTH;
}

size_t Map::height() const {
	return MAP_HEIGHT;
}

bool Map::checkIntersection(float x, float y) const {
	size_t i = (x - CELL_SIZE / 2) / CELL_SIZE;
	size_t j = (y + CELL_SIZE / 2) / CELL_SIZE;

	return p_markup[(j - 1) * MAP_WIDTH + i] == '1';
}

sf::Sprite& Map::getWallSprite(float x, float y) {
	x -= CELL_SIZE / 2; 
	y += CELL_SIZE / 2;
    size_t i = x / CELL_SIZE;
	size_t j = y / CELL_SIZE;

	sf::Sprite wallSprite = textures[p_markup[(j - 1) * MAP_WIDTH + i]];

	//std::cout << "x " << abs(x - i * CELL_SIZE) << std::endl << "y " << abs(y - j * CELL_SIZE) << std::endl;
	
	float offsetX = abs(x - i * CELL_SIZE); 
	if (offsetX > 29) {
		offsetX = 0;
	}

	float offsetY = abs(y - j * CELL_SIZE);
	if (offsetY > 29) {
		offsetY = 0;
	}

	if (offsetX >= offsetY) {
		wallSprite.setTextureRect(sf::IntRect((int) (x) % CELL_SIZE, 0, 1, wallSprite.getTextureRect().height));
	}
	else {
		wallSprite.setTextureRect(sf::IntRect((int) (y) % CELL_SIZE, 0, 1, wallSprite.getTextureRect().height));
	}

	return wallSprite;
}

const char& Map::getMarkup() {
	return *p_markup;
}

std::vector<sf::RectangleShape>& Map::getGraphicPresentation() {
	return walls;
}