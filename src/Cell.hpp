//
//  Cell.h
//  my_first_sfml
//
//  Created by Arnau Jutglar Puig on 12/11/23.
//  Copyright © 2023 Arnau Jutglar Puig. All rights reserved.
//

#ifndef Cell_h
#define Cell_h

#include <SFML/Graphics.hpp>
#include <vector>
#include <random>
#include <iostream>

class Cell : public sf::RectangleShape {
protected:
    bool is_alive;
public:
    Cell(sf::Vector2f);
    void updateColor();
    void updateLife(std::vector<Cell>& ptr, int x_pos, int y_pos, int rows, int cols);
};


#endif /* Cell_h */
