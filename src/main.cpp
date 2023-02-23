#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#include <cmath>

#include "math.hpp"
#include "player.hpp"


int main() {
    sf::RenderWindow window(sf::VideoMode(512,480), "My Window");

    sf::Vector2f map_size = {32, 30};
    sf::Vector2f cell_size = {16,16};
    std::vector<int> map_grid;
    sf::Color dark_gray = {134, 136, 138};

    Player player(sf::Vector2f(100,100));


    map_grid.resize(map_size.x * map_size.y);

    window.setActive(true);  


    sf::Clock clock;
    while(window.isOpen())
    {
        sf::Time elapsed = clock.restart();
        auto delta_time = elapsed.asSeconds();
        sf::Event event;

        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed) window.close();
            if(event.type == sf::Event::MouseButtonPressed){
                auto mouse_pos = sf::Mouse::getPosition(window);
                auto col = std::trunc(mouse_pos.x / cell_size.x);
                auto row = std::trunc(mouse_pos.y / cell_size.y);
                map_grid[row * map_size.x + col] = 1;
                //std::cout << row << " " << col << "\n";
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) player.position.y -= 100 * delta_time;
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) player.position.x -= 100 * delta_time;
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) player.position.y += 100 * delta_time;
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) player.position.x += 100 * delta_time;

        }
        window.clear(sf::Color::Black);
        
        //Draw the under grid
        sf::RectangleShape cell(cell_size);
        for(int y=0; y < map_size.y; ++y ){
            for(int x=0; x < map_size.x; ++x){
                int cell_value = map_grid[y*map_size.x + x];
                if(cell_value == 1){
                    cell.setPosition(sf::Vector2f(x * cell_size.x ,y * cell_size.y));
                    cell.setFillColor(sf::Color::Red);
                    window.draw(cell);
                }else{
                    cell.setPosition(sf::Vector2f(x * cell_size.x ,y * cell_size.y));
                    cell.setFillColor(sf::Color::Black);
                    cell.setOutlineThickness(1);
                    cell.setOutlineColor(dark_gray);
                    window.draw(cell);
                }

            }
        }

        player.render(window);


        sf::VertexArray line(sf::Lines, 2);
        line[0] = sf::Vertex(player.get_center(), sf::Color::White);
        line[1] = sf::Vertex(sf::Vector2f(sf::Mouse::getPosition(window)), sf::Color::White);
        

        sf::CircleShape pointer(8);
        pointer.setFillColor(sf::Color::Green);
        pointer.setPosition(sf::Vector2f(sf::Mouse::getPosition(window)));
        window.draw(pointer);


        window.draw(line);



        window.display();
    }

    return 0;
}