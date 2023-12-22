
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// In order to load the resources like background.png, you have to set up
// your target scheme:
//
// - Select "Edit Scheme…" in the "Product" menu;
// - Check the box "use custom working directory";
// - Fill the text field with the folder path containing your resources;
//        (e.g. your project folder)
// - Click OK.
//

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
    sf::RenderWindow window(vm, "La meva finestra", sf::Style::None | sf::Style::Titlebar | sf::Style::Close);
        
    sf::Music music;
    if (!music.openFromFile("Resources/Music/rick_and_morty.ogg")) {return EXIT_FAILURE;}
    music.play();
    
    sf::CircleShape circle(50);
    circle.setPosition(30, 30);
        
    // Grid
    int n = 10;
    if (argc == 1) {
        n = 10;
    } else if (argc == 2) {
        n = atoi(argv[1]);
        std::cout << n << std::endl;
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

