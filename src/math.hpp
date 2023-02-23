#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>

float dot(const sf::Vector2f& a, const sf::Vector2f& b){
    return a.x * b.x + a.y * b.y; 
}

float mag_sqr(const sf::Vector2f& vec){
    return dot(vec, vec);
} 

float mag(const sf::Vector2f& vec){
    return std::sqrt(mag_sqr(vec));
}

sf::Vector2f norm(const sf::Vector2f vec){
    return sf::Vector2f(vec * (1 / mag(vec) ));
}