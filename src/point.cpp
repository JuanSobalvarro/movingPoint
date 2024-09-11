#include <point.hpp>

Point::Point(float radius, sf::Vector2f initialPos, sf::Color color, sf::RenderWindow& parentWindow)
{
    circleShape = new sf::CircleShape(radius);
    circleShape->setFillColor(color);
    window = &parentWindow;
    windowSize = window->getSize();
    windowOffset = {windowSize.x/2 + radius, windowSize.y/2 + radius};
    position = {windowOffset.x + initialPos.x, windowOffset.y + initialPos.y};
    updatePos();

}

Point::~Point()
{
    delete[] circleShape;
}

sf::Vector2f Point::getPos()
{
    return position;
}

void Point::setVelocity(sf::Vector2f newVelocity)
{
    velocity = newVelocity;
}

void Point::draw()
{
    window->draw(*circleShape);
}

void Point::movePoint(sf::Keyboard::Key key)
{
    if (key == sf::Keyboard::Up)
    {
        velocity.y -= acceleration;
    }
    if (key == sf::Keyboard::Down)
    {
        velocity.y += acceleration;
    }
    if (key == sf::Keyboard::Right)
    {
        velocity.x += acceleration;
    }
    if (key == sf::Keyboard::Left)
    {
        velocity.x -= acceleration;
    }
    
    if (key < 71 || key > 74)
        velocity = {0, 0};

    updatePos();
}

// Returns the Circle Shape of point
sf::CircleShape Point::getShape()
{
    return *circleShape;
}

void Point::updatePos()
{
    sf::Vector2f newPos = {position.x + velocity.x, position.y + velocity.y};
    if (newPos.x >= windowSize.x || newPos.x <= 0)
        return;
    if (newPos.y >= windowSize.y || newPos.y <= 0)
        return;
    position = {newPos.x, newPos.y};
    circleShape->setPosition(position);
}
