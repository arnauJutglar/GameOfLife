//
//  Cell_grid.hpp
//  my_first_sfml
//
//  Created by Arnau Jutglar Puig on 12/11/23.
//  Copyright © 2023 Arnau Jutglar Puig. All rights reserved.
//

#ifndef Cell_grid_h
#define Cell_grid_h

#include <SFML/Graphics.hpp>
#include <random>

#include "Cell.hpp"
#include "Square_grid.hpp"



class Cell_grid : public Square_grid<Cell> {
private:
    void update_life();
    void update_color();
public:
    Cell_grid(sf::RenderWindow&, int);
    void update();
};


#endif /* Cell_grid_h */
