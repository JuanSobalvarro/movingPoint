#include <SFML/Graphics.hpp>

void movePoint(sf::CircleShape& point, sf::Event& event, sf::Vector2f& velocity);

int main(int argc, char *argv[])
{
    // Render window object
    auto window = sf::RenderWindow{ { 1080u, 720u }, "Moving Point" };
    window.setFramerateLimit(144);

    sf::CircleShape point(20.f);
    point.setFillColor(sf::Color(0, 255, 255));
    point.setPosition(1080/2 - 20, 720/2 - 20);

    sf::Vector2f currentVelocity = {0, 0};

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
                movePoint(point, event, currentVelocity);
            }
        }

        window.clear();
        // Draw point on screen
        window.draw(point);
        window.display();
    }
}

void movePoint(sf::CircleShape& point, sf::Event& event, sf::Vector2f& velocity)
{
    float acceleration = 10;

    if (event.key.code == sf::Keyboard::Up)
    {
        velocity.y -= acceleration;
    }
    else if (event.key.code == sf::Keyboard::Down) 
    {
        velocity.y += acceleration;
    }  
    else if (event.key.code == sf::Keyboard::Left) 
    {
        velocity.x -= acceleration;
    }  
    else if (event.key.code == sf::Keyboard::Right) 
    {
        velocity.x += acceleration;
    }  

    point.move(velocity);
}