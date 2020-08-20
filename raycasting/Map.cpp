#include "map.h"

Map::Map() {
	char markup[15][16] = {
		"111111111111111",
		"1             1",
		"1      11111  1",
		"1             1",
		"1        111111",
		"1             1",
		"1     111     1",
		"1       1     1",
		"1   1   1     1",
		"1   1   1  1111",
		"1       1     1",
		"1       1     1",
		"1       1     1",
		"1             1",
		"111111111111111"};

	for (int i = 0; i < MAP_HEIGHT; ++i) {
		for (int j = 0; j < MAP_WIDTH; ++j) {
			if (markup[i][j] == '1') {
				sf::RectangleShape* rectangle = new sf::RectangleShape(sf::Vector2f(CELL_SIZE, CELL_SIZE));
				rectangle->setFillColor(sf::Color::Cyan);
				rectangle->setOrigin(CELL_SIZE / 2, CELL_SIZE / 2);
				rectangle->setPosition(CELL_SIZE * (j + 1), CELL_SIZE * (i + 1));
				walls.push_back(rectangle);
			}
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

