#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>


struct SnakeSegment
{
    SnakeSegment(int x, int y) : position(x,y) {}
    SnakeSegment() : position(-1,-1) {}
    sf::Vector2i position;

};

using SnakeContainer = std::vector<SnakeSegment>;
enum class Direction {None, Up, Down, Left, Right};

class Player
{
public:
    Player();
    ~Player();

    void Move();
    void Tick();
    void Reset();
    void Extend();
    void CheckCollision();
    void Render(sf::RenderWindow&);

    void SetDirection(Direction);
    Direction GetDirection();
    Direction GetPhysicalDirection();

    sf::Vector2i GetPosition();

    bool HasLost();
    void Lose();

    float GetSpeed();
    void IncreaseSpeed();


    void IncreaseScore();

private:
    SnakeContainer snakeBody;
    sf::RectangleShape bodyRect;
    unsigned int size;
    float speed;
    bool hasLost;
    Direction dir;

    sf::Font font;
    sf::Text text;
    long long int score;

    sf::RectangleShape rect;


};

#endif // PLAYER_H
