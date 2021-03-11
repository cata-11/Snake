#ifndef STATE_GAME_H
#define STATE_GAME_H


class State_Game
{
public:
    State_Game();
    virtual ~State_Game();

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

#endif // STATE_GAME_H
