#include "Game.h"
int main()
{
    Game game;

    while(game.GetWindow()->IsOpen())
    {
        game.HandleInput();
        game.Update();
        game.Render();
        game.RestartClock();
    }
}
