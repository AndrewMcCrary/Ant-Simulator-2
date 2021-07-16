#include <iostream>
#include <SFML/Graphics.hpp>

#include "window.h"

int fmain(void)
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}

int main(void) {
    window* w = new window(WINDOW_RES_X, WINDOW_RES_Y, TICK_60HZ);

    return 0;
}
