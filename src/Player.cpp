#include "Player.h"

#include <string>

Player::Player() : size(16)
{
    Reset();
    //std::cout<<speed;
    font.loadFromFile("arial.ttf");
    text.setFont(font);
    text.setCharacterSize(25);
    text.setFillColor(sf::Color::White);
}

Player::~Player()
{
    //dtor
}

void Player::Reset()
{
    dir = Direction::None;
    speed = 10.f;
    hasLost = false;
    score = 2;
    snakeBody.clear();
    for(int i=3; i>0; --i)
        snakeBody.push_back(SnakeSegment(5+i,5));
}

void Player::Render(sf::RenderWindow& window)
{
    for(auto i = snakeBody.begin(); i!=snakeBody.end(); ++i)
    {
        bodyRect.setSize(sf::Vector2f(size-1,size-1));
        bodyRect.setPosition(i->position.x*size,i->position.y*size);
        bodyRect.setFillColor(sf::Color::Green);
        if(i==snakeBody.begin()) bodyRect.setFillColor(sf::Color::Yellow);
        window.draw(bodyRect);
    }

    if(HasLost())
    {
        rect.setSize(sf::Vector2f(512,512));
        rect.setPosition(0,0);
        rect.setFillColor(sf::Color(70,70,70,150));
        window.draw(rect);
        text.setString("You lose (");
        text.setPosition(sf::Vector2f(200,150));
        window.draw(text);
        text.setString("Your score");
        text.setPosition(sf::Vector2f(195,200));
        window.draw(text);
        text.setString({std::to_string(score)});
        text.setPosition(sf::Vector2f(250,240));
        window.draw(text);
        text.setString("Press Space to restart");
        text.setPosition(sf::Vector2f(130,380));
        window.draw(text);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            Reset();
        }
    }
}

void Player::SetDirection(Direction dir)
{
    this->dir = dir;
}

Direction Player::GetDirection()
{
    return dir;
}

void Player::Move()
{
    for(int i=snakeBody.size()-1; i>0; --i)
        snakeBody[i].position = snakeBody[i-1].position;

    if(dir == Direction::Up)
        snakeBody[0].position.y--;
    else if(dir == Direction::Down)
        snakeBody[0].position.y++;
    else if(dir == Direction::Left)
        snakeBody[0].position.x--;
    else if(dir == Direction::Right)
        snakeBody[0].position.x++;
}

void Player::Tick()
{
    if(dir == Direction::None)
        return;
    Move();
    CheckCollision();
}

float Player::GetSpeed()
{
    return speed;
}

void Player::Extend()
{
    snakeBody.push_back(SnakeSegment());
    //printf("got");
}

sf::Vector2i Player::GetPosition()
{
    return snakeBody.front().position;
}
void Player::IncreaseSpeed()
{
    speed += 0.1;
    //printf("%f",speed);
}

void Player::CheckCollision()
{
    if (snakeBody.size() == 3)
    {
        return;
    }
    for(auto i = snakeBody.begin()+1; i!= snakeBody.end(); ++i)
        if(snakeBody.front().position == i->position)
        {
            Lose();
            return;
        }
}

Direction Player::GetPhysicalDirection()
{
    if(snakeBody.size() <= 1)
    {
        return Direction::None;
    }

    SnakeSegment& head = snakeBody[0];
    SnakeSegment& neck = snakeBody[1];

    if(head.position.x == neck.position.x)
    {
        return (head.position.y > neck.position.y ? Direction::Down : Direction::Up);
    }
    else if(head.position.y == neck.position.y)
    {
        return (head.position.x > neck.position.x ? Direction::Right : Direction::Left);
    }

    return Direction::None;
}

bool Player::HasLost()
{
    return hasLost;
}
void Player::Lose()
{
    hasLost = true;
}

void Player::IncreaseScore(){
    score++;
}
