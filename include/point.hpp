#ifndef POINT_HPP
#define POINT_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class Point
{
public:
    Point(float radius, sf::Vector2f initialPos, sf::Color color, sf::RenderWindow& parentWindow);
    ~Point();

    void draw();

    sf::Vector2f getPos();
    sf::CircleShape getShape();

    void setVelocity(sf::Vector2f newVelocity);
    
    void movePoint(sf::Keyboard::Key key);
    void updatePos();
    void changeRadius(float newRadius);
    void changeColor(sf::Color newColor);

private:
    sf::RenderWindow* window;

    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::CircleShape* circleShape;
    sf::Color color;

    float acceleration = 10;
    float desacceleration = 5;
    float maxVelocity = 60;

    sf::Vector2u windowOffset;
};

#endif