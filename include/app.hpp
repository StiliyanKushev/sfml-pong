#pragma once

#include <SFML/Graphics.hpp>

class App
{
public:
    /**
     * Called once at the start.
     * Can be used to prepare or load any assets or data.
     */
    static void setup(sf::RenderWindow &window);

    /**
     * Called each frame before the buffers are switched.
     * (i.e before display is called).
     */
    static void draw(sf::RenderWindow &window);

    /**
     * Called each time the event queue receives a window event.
     */
    static void event(sf::RenderWindow &window, sf::Event &e);
};