#ifndef WORLD_H
#define WORLD_H
#include <SFML/Graphics.hpp>
#include "Window.h"
#include "Player.h"

class World
{
public:
    World(sf::Vector2u);
    ~World();

    void BuildWalls(sf::RenderWindow& window);
    void RespawnApple();

    void Update(Player& snake);
    void Render(sf::RenderWindow&);


private:
    Player snake;

    unsigned int blockSize;

    sf::Vector2u windowSize;

    sf::RectangleShape walls[4];

    sf::Vector2i applePos;
    sf::CircleShape apple;


};

#endif // WORLD_H
