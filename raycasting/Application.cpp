#include <SFML/Graphics.hpp>
#include "Renderer.h"

using namespace sf;

int main() {
	RenderWindow window(VideoMode(640, 480), "ray casting");
	Renderer renderer = Renderer(window);

	while (window.isOpen()) {
		Event event;

		while (window.pollEvent(event)) {

			if (event.type == Event::Closed)
				window.close();

		}
		window.clear();
		renderer.render();
		window.display();
	}

	return 0;
}