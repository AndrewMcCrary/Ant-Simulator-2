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


	for (int i = 0; i < 720; i++) {
		w->addAnt(new ant(WINDOW_RES_X / 2.f, WINDOW_RES_Y / 2.f, (float)i));
	}

	//w->addHome(new home(500, 500, 30));
	w->addTrail(new trail(300, 300, trailType::ToHome, TRAIL_LIFETIME, true));
	w->addTrail(new trail(300, 600, trailType::ToFood, TRAIL_LIFETIME, true));

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
				w->addFood(new food(Mouse::getPosition(win).x, Mouse::getPosition(win).y));
				//w->addTrail(new trail(Mouse::getPosition(win).x, Mouse::getPosition(win).y, trailType::ToFood, TRAIL_LIFETIME, true));
			}


		// Clear frame
		win.clear(BACK_COLOR);

		// update world
		w->tick(tickRate * dt);

		// Draw all objs
		if (VISIBLE_TRAILS)
			for (size_t i = 0; i < w->getTrails().size(); i++) {
				win.draw(*w->getTrails()[i]->getAsset());
			}

		for (size_t i = 0; i < w->getFoods().size(); i++) {
			win.draw(*w->getFoods()[i]->getAsset());
		}

		for (size_t i = 0; i < w->getAnts().size(); i++) {
			win.draw(*w->getAnts()[i]->getAsset());
		}

		for (size_t i = 0; i < w->getHomes().size(); i++) {
			win.draw(*w->getHomes()[i]->getAsset());
		}


		win.display();


		dt = c.restart().asSeconds();
	}


}