#include <SFML/Graphics.hpp>
#include <point.hpp>

int main(int argc, char *argv[])
{
    // Render window object
    auto window = sf::RenderWindow{ { 1080u, 720u }, "Moving Point" };
    window.setFramerateLimit(144);

    Point point = Point(20.f, {0, 0}, sf::Color(0, 255, 255), window);

    // execution loop
    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed)
            {
                point.movePoint(event.key.code);
            }
            else if (event.type == sf::Event::KeyReleased)
            {
                point.setVelocity({0, 0});
            }
        }

        window.clear();
        // Draw point on screen
        point.draw();
        window.display();
    }
}