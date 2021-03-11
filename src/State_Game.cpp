#include "State_Game.h"
Game::Game() : world(sf::Vector2u(512,512))
{
    clock.restart();
    srand(time(nullptr));
    deltaTime = 0.f;
}
Game::~Game()
{
    //dtor
}
void Game::HandleInput()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && snake.GetPhysicalDirection() != Direction::Down)
        snake.SetDirection(Direction::Up);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && snake.GetPhysicalDirection() != Direction::Right && snake.GetDirection() != Direction::None)
        snake.SetDirection(Direction::Left);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && snake.GetPhysicalDirection() != Direction::Left)
        snake.SetDirection(Direction::Right);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && snake.GetPhysicalDirection() != Direction::Up)
        snake.SetDirection(Direction::Down);
}
void Game::Update()
{
    window.Update();
    step = 1.f/snake.GetSpeed();
    if(deltaTime >= step)
    {
        if(!snake.HasLost())
        {
            snake.Tick();
            world.Update(snake);
        }
        //std::cout<<"tick";
        deltaTime-=step;
    }
}
void Game::Render()
{
    window.BeginDraw();
    snake.Render(*window.GetRenderWindow());
    world.Render(*window.GetRenderWindow());
    //std::cout<<"Render";
    window.EndDraw();
}
sf::Time Game::GetDeltaTime()
{
    return clock.getElapsedTime();
}
void Game::RestartClock()
{
    deltaTime += clock.restart().asSeconds();
}
Window* Game::GetWindow()
{
    return &window;
}
