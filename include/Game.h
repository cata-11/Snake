#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "Window.h"
#include "Player.h"
#include "World.h"

class Game
{
public:
    Game();
    ~Game();

    void HandleInput();
    void Update();
    void Render();

    sf::Time GetDeltaTime();
    void RestartClock();

    Window* GetWindow();

private:
    Window window;
    Player snake;
    World world;
    sf::Clock clock;
    float deltaTime;
    float step;
    std::string state;
};

#endif // GAME_H
