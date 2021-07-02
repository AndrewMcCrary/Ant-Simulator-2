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

	//w->addAnt(new ant(WINDOW_RES_X / 2.f, WINDOW_RES_Y / 2.f, 95.f));
	//w->addAnt(new ant(WINDOW_RES_X / 2.f, WINDOW_RES_Y / 2.f, 100.f));
	//w->addAnt(new ant(WINDOW_RES_X / 2.f, WINDOW_RES_Y / 2.f, 90.f));

	for (int i = 0; i < 360; i++) {
		w->addAnt(new ant(WINDOW_RES_X / 2.f, WINDOW_RES_Y / 2.f, (float)i));
	}

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
				w->getAnts()[0]->setRotation(Mouse::getPosition(win).x - w->getAnts()[0]->getX(),
											 Mouse::getPosition(win).y - w->getAnts()[0]->getY(),
											 tickRate * dt);
			}


		// Clear frame
		win.clear(BACK_COLOR);

		// update world
		w->tick(tickRate * dt);


		// Draw all objs
		for (size_t i = 0; i < w->getAnts().size(); i++) {
			win.draw(*w->getAnts()[i]->getAsset());
		}

		win.display();


		dt = c.restart().asSeconds();
	}


}