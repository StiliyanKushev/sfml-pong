#include <iostream>
#include <memory>
#include <array>
#include "app.hpp"
#include "platform.hpp"
#include "ball.hpp"

static std::unique_ptr<Platform> player;
static std::unique_ptr<Platform> computer;
static std::unique_ptr<Ball> ball;
static std::array<std::unique_ptr<Platform>, 2> walls;

/**
 * Simply AI function to move the computer
 * in the direction of the ball.
 */
static void moveComputerAI()
{
    if(ball->position.y > computer->position.y)
    {
        computer->velocity.y = +Platform::SPEED;
    }
    else if(ball->position.y < computer->position.y)
    {
        computer->velocity.y = -Platform::SPEED;
    }
    else
    {
        computer->velocity.y = 0;
    }
}

void App::setup(sf::RenderWindow &window)
{
    auto WINDOW_SIZE = window.getSize();

    // initiate the player at the left of the screen
    player = std::make_unique<Platform>(
        sf::Vector2f(0, WINDOW_SIZE.y / 2));

    // initiate the computer at the right of the screen
    computer = std::make_unique<Platform>(sf::Vector2f(
        WINDOW_SIZE.x - Platform::WIDTH, WINDOW_SIZE.y / 2));

    // initiate the ball at the center of the screen
    ball = std::make_unique<Ball>(sf::Vector2f(
        WINDOW_SIZE.x/2,WINDOW_SIZE.y/2));

    // initiate the walls at top and bottom
    walls[0] = std::make_unique<Platform>(
        sf::Vector2f(0, 50));
    walls[0]->size.x = WINDOW_SIZE.x;
    walls[0]->size.y = 1;
    
    walls[1] = std::make_unique<Platform>(
        sf::Vector2f(0, WINDOW_SIZE.y-50));
    walls[1]->size.x = WINDOW_SIZE.x;
    walls[1]->size.y = 1;

    // give the ball an initial velocity to start the game
    ball->velocity.x = -Ball::SPEED_X;
    ball->velocity.y = -2;
}

void App::draw(sf::RenderWindow &window)
{
    // make sure computer plays the game
    moveComputerAI();

    // apply velocity for every entity
    player->Move();
    computer->Move();
    ball->Move();

    // render everything on screen
    player->Draw(window);
    computer->Draw(window);
    ball->Draw(window);
    for(auto &wall : walls)
        wall->Draw(window);

    // computer can never lose here.
    // check if player lost and exit the app.
    if(ball->position.x < player->position.x)
        exit(0);
}

void App::event(sf::RenderWindow &window, sf::Event &e)
{
    // if both keys are pressed, don't move
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
    && sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        player->velocity.y = 0;
    }
    // handle up key
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        player->velocity.y = -Platform::SPEED;
    }
    // handle down key
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        player->velocity.y = +Platform::SPEED;
    }
    // nothing is pressed, don't move
    else {
        player->velocity.y = 0;
    }
}