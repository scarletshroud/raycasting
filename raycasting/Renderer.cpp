#include "Renderer.h"

Renderer::Renderer(sf::RenderWindow& window) : 
	window(window),  
	map(), 
	enemy(map, player),
	player(map, enemy) 
{
}

Renderer::~Renderer() {
}

void Renderer::update(float time) {
	player.update(window, time);
	enemy.update(window, time);
}

void Renderer::render() {

	for (const auto& rectangle : map.getGraphicPresentation()) {
		window.draw(rectangle);
	}

	window.draw(player.getPlayerModel());
	window.draw(enemy.getEnemyModel()); 
     
	for (const auto& sightLine : player.getSightLines()) {
		window.draw(sightLine);
	} 

	for (const auto& wall : player.getWalls()) {
		window.draw(wall);
	} 

} 