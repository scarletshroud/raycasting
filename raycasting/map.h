#ifndef MAP_H
#define MAP_H

#include "SFML/Graphics.hpp"

class Map {
public:
	Map(); 
	~Map(); 

	size_t width() const;
	size_t height() const;

	bool checkIntersection(float, float) const;

	sf::Sprite& getWallSprite(float, float);
	static const char& getMarkup(); 
	std::vector<sf::RectangleShape>& getGraphicPresentation();

private:
	const size_t MAP_WIDTH = 15;
	const size_t MAP_HEIGHT = 15;
	const size_t CELL_SIZE = 30;

	sf::Texture wallTexture;

	static const char* p_markup;
	std::vector<sf::RectangleShape> walls;
	std::map<char, sf::Sprite> textures; 
};

#endif