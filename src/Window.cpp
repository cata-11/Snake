#include "Window.h"

Window::Window() : title("Snake"), size(sf::Vector2u(512,512)), isOpen(true)
{
    Create();
}

Window::~Window()
{
    Destroy();
}

void Window::Create()
{
    window.create(sf::VideoMode(size.x, size.y),title,sf::Style::None);
}
void Window::Destroy()
{
    window.close();
}

void Window::BeginDraw()
{
    window.clear(sf::Color::Black);
}
void Window::Draw(sf::Drawable& d)
{
    window.draw(d);
}
void Window::EndDraw()
{
    window.display();
}

void Window::Update()
{
    sf::Event e;
    while(window.pollEvent(e))
    {
        if(e.type==sf::Event::Closed)
        {
            isOpen = false;
            window.close();

        }
    }
}
bool Window::IsOpen()
{
    return isOpen;
}

sf::RenderWindow* Window::GetRenderWindow()
{
    return &window;
}



