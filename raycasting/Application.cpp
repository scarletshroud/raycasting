#include <SFML/Graphics.hpp>
#include "Renderer.h"

using namespace sf;

int main() {
	RenderWindow window(VideoMode(1280, 720), "ray casting");
	sf::Clock clock;
	Renderer renderer = Renderer(window);

	while (window.isOpen()) {

		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time /= 800;

		Event event;

		while (window.pollEvent(event)) {

			if (event.type == Event::Closed)
				window.close();

		}
		window.clear();
		renderer.update(time);
		renderer.render();
		window.display();
	}

	return 0;
}