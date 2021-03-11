#include "World.h"
#include <stdio.h>
World::World(sf::Vector2u _windowSize) : windowSize(_windowSize)
{
    blockSize = 16;

    apple.setRadius(blockSize/2);
    apple.setFillColor(sf::Color::Red);

    RespawnApple();

    for(int i=0; i<4; ++i)
    {
        walls[i].setFillColor(sf::Color::White);
        walls[i].setOutlineColor(sf::Color::Black);
        if(i%2==0)
            walls[i].setSize(sf::Vector2f(windowSize.x, blockSize));
        else
            walls[i].setSize(sf::Vector2f(blockSize,windowSize.y));
        if(i<2)
            walls[i].setPosition(-1,-1);
        else
        {
            walls[i].setOrigin(walls[i].getSize());
            walls[i].setPosition(sf::Vector2f(windowSize));
        }
    }
}

World::~World()
{
    //dtor
}

void World::RespawnApple()
{
    int maxX = windowSize.x / blockSize - 2;
    int maxY = windowSize.y / blockSize - 2;
    applePos = sf::Vector2i(rand()%maxX+1, rand()%maxY+1);
    apple.setPosition(applePos.x * blockSize, applePos.y * blockSize);
}

void World::Render(sf::RenderWindow& window)
{
    for(int i=0; i<4; ++i)
    {
        window.draw(walls[i]);
    }
    window.draw(apple);
}

void World::Update(Player& snake)
{
    if(snake.GetPosition()==applePos)
    {
        snake.Extend();
        snake.IncreaseScore();
        snake.IncreaseSpeed();
        RespawnApple();
    }

    if(snake.GetPosition().x>=windowSize.x/blockSize - 1 ||
            snake.GetPosition().y>=windowSize.y/blockSize - 1 ||
            snake.GetPosition().x <= 0 || snake.GetPosition().y <= 0)
    {
        //printf("reset");
        snake.Lose();
    }
}
