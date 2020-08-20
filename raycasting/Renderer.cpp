#include "Renderer.h"

Renderer::Renderer(sf::RenderWindow &window) {
	this->window = &window;
	map = new Map();
	player = new Player();
}

Renderer::~Renderer() {
	delete map;
	delete player;
}

void Renderer::render() {
	//Rendering map//
	for (const auto rectangle : map->getGraphicPresentation()) {
		window->draw(*rectangle);
	}
	window->draw(*player->getPlayerModel());
	
} 