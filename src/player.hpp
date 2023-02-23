#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "math.hpp"

class Player
{
    private:
        //sf::CircleShape sprite(); 
    public:
        Player(const float _x, const float _y) : position(sf::Vector2f(_x, _y)){}
        Player(const sf::Vector2f& pos) : position(pos) {}



        constexpr static float radius = 10;
        sf::Vector2f position;
        sf::Vector2f velocity;


        void render(sf::RenderWindow& window) const;
        //void update()
        sf::Vector2f get_center() const;
};

void Player::render(sf::RenderWindow& window) const {
    sf::CircleShape circle(radius);
    circle.setFillColor(sf::Color::Yellow);
    circle.setPosition(position);
    window.draw(circle);
}

sf::Vector2f Player::get_center() const {
    return sf::Vector2f( position.x + radius, position.y + radius);
}