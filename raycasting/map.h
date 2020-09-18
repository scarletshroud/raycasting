#ifndef MAP_H
#define MAP_H

#include "SFML/Graphics.hpp"

class Map {
private:

	const int MAP_WIDTH = 15;
	const int MAP_HEIGHT = 15;
	const int CELL_SIZE = 30;
	static const char* p_markup;
	std::vector<sf::RectangleShape*> walls;

public:
	Map(); 
	~Map(); 

	int width();
	int height();
	static const char* getMarkup(); 
	std::vector<sf::RectangleShape*>& getGraphicPresentation();

	bool checkIntersection(float x, float y); 
};

#endif