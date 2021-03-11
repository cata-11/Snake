#ifndef WINDOW_H
#define WINDOW_H
#include <SFML/Graphics.hpp>

class Window
{
public:
    Window();
    ~Window();

    void BeginDraw();
    void Draw(sf::Drawable&);
    void EndDraw();

    void Update();

    bool IsOpen();

    sf::RenderWindow* GetRenderWindow();

private:
    sf::RenderWindow window;

    std::string title;
    sf::Vector2u size;

    bool isOpen;

    void Create();
    void Destroy();
};

#endif // WINDOW_H
