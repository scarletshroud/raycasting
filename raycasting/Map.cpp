#include "map.h"
#include <iostream>

Map::Map() {
	 char markup[226] = {
		"111111111111111"\
		"1             1"\
		"1      11111  1"\
		"1             1"\
		"1        111111"\
		"1             1"\
		"1     111     1"\
		"1       1     1"\
		"1   1   1     1"\
		"1   1   1  1111"\
		"1       1     1"\
		"1       1     1"\
		"1       1     1"\
		"1             1"\
		"111111111111111"};

	 p_markup = markup;

	 int j = 0;

	 for (int i = 0; i < MAP_HEIGHT * MAP_WIDTH; ++i) {

		 if (markup[i] == '1') {
			 sf::RectangleShape* rectangle = new sf::RectangleShape(sf::Vector2f(CELL_SIZE, CELL_SIZE));
			 rectangle->setFillColor(sf::Color::Cyan);
			 rectangle->setOrigin(CELL_SIZE / 2, CELL_SIZE / 2);
			 rectangle->setPosition(CELL_SIZE * (i % MAP_WIDTH + 1), CELL_SIZE * (j + 1));
			 walls.push_back(rectangle);
		 }

		 if (i % MAP_HEIGHT == 14) {
			 j++;
		 }

	 }
}

Map::~Map() {
	delete[] p_markup;
	for (const auto& rectangle : walls) {
		delete rectangle;
	}
}

int Map::width() {
	return MAP_WIDTH;
}

int Map::height() {
	return MAP_HEIGHT;
}

char* Map::getMarkup() {
	return p_markup;
}

std::vector<sf::RectangleShape*>& Map::getGraphicPresentation() {
	return walls;
}

//I should refactor this with using a simple array 
bool Map::checkIntersection(float x, float y) {
	for (const auto rectangle : walls) {
		if (x >= rectangle->getPosition().x - CELL_SIZE / 2 && x <= rectangle->getPosition().x + CELL_SIZE / 2)
			if (y >= rectangle->getPosition().y - CELL_SIZE / 2 && y <= rectangle->getPosition().y + CELL_SIZE / 2)
				return true;
	}
	return false;
}