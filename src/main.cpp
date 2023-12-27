/**
 It accepts, as a main argument, the size in pixels of the cells.
 */

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <unistd.h>
#include <cstdlib>

#include "Grid.hpp"
#include "Square_grid.hpp"
#include "Cell.hpp"
#include "Cell_grid.hpp"


int main(int argc, char const** argv) {
    sf::VideoMode vm(800,600);
    sf::RenderWindow window(vm, "Conway's Game of Life", sf::Style::None | sf::Style::Titlebar | sf::Style::Close);
        
    sf::Music music;
    if (!music.openFromFile("Resources/Music/rick_and_morty.ogg")) {return EXIT_FAILURE;}
    music.play();
            
    // Grid
    int n = 10;
    if (argc == 1) {
        n = 10;
    } else if (argc == 2) {
        n = atoi(argv[1]);
        if (n < 0 || n > 100) {
            std::cout << "Sizes out of accepted range. Execution aborted." << std::endl;
            return 1;
        }
    } else {
        std::cout << "Incorrect number of arguments. Execution aborted." << std::endl;
        return 1;
    }

    Cell_grid cell_grid(window, n);
            
    while (window.isOpen()) {
        sf::Event event;
        
        
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {window.close();}
            
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
            
        }
        
        window.clear();
        
        cell_grid.draw();

        cell_grid.update();
        
        window.display();
        
        sleep(1);
    }
    
    
    return EXIT_SUCCESS;
}

