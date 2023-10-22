#include <SFML/Graphics.hpp>
#include "app.hpp"

int main()
{
    auto window = sf::RenderWindow{ { 800, 800 }, "Pong" };
    window.setFramerateLimit(144);

    App::setup(window);

    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else 
            {
                App::event(window, event);
            }
        }

        window.clear();
        App::draw(window);
        window.display();
    }
}