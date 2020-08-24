#include "Renderer.h"

Renderer::Renderer(sf::RenderWindow& window) {
	this->window = &window;
	map = new Map();
	player = new Player(map);
}

Renderer::~Renderer() {
	delete map;
	delete player;
}

void Renderer::update(float time) {
	player->update(*window, time);
}

void Renderer::render() {
	
	for (const auto rectangle : map->getGraphicPresentation()) {
		window->draw(*rectangle);
	}

	window->draw(*player->getPlayerModel());
     
	for (const auto sightLine : player->getSightLines()) {
		window->draw(*sightLine);
	}

	for (const auto wall : player->getWalls()) {
		window->draw(*wall);
	}
} 