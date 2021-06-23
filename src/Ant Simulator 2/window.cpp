#include "window.h"

using namespace sf;

window::window(int resX, int resY, float tickRate) {

	ContextSettings settings;
	settings.antialiasingLevel = 6;

	RenderWindow win(sf::VideoMode(WINDOW_RES_X, WINDOW_RES_Y), WINDOW_TITLE, sf::Style::Close, settings);
	win.setFramerateLimit(FRAME_RATE_60HZ);

	world* w = new world(WINDOW_RES_X, WINDOW_RES_Y);

	Clock c;
	float dt = 1.f / tickRate;

	while (win.isOpen()) {
		Event e;
		while (win.pollEvent(e)) {
			if (e.type == Event::Closed)
				win.close();

			if (e.type == Event::KeyPressed && e.key.code == Keyboard::Escape)
				win.close();
		}

		// Click to move
		if (Mouse::isButtonPressed(Mouse::Button::Left))
			if (Mouse::getPosition(win).x > 0 && Mouse::getPosition(win).x < WINDOW_RES_X && Mouse::getPosition(win).y > 0 && Mouse::getPosition(win).y < WINDOW_RES_Y) {
				w->getAnts()[0]->moveToPoint(Mouse::getPosition(win).x, Mouse::getPosition(win).y);

			}


		// Clear frame
		win.clear(BACK_COLOR);

		// update world

		// Draw all objs

		win.display();


		dt = c.restart().asSeconds();
	}


}