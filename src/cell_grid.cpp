//
//  Cell_grid.cpp
//  my_first_sfml
//
//  Created by Arnau Jutglar Puig on 12/11/23.
//  Copyright © 2023 Arnau Jutglar Puig. All rights reserved.
// 

#include <SFML/Graphics.hpp>

#include "Cell_grid.hpp"

Cell_grid::Cell_grid(sf::RenderWindow& win, int n) : Square_grid<Cell>(win, n) {
    update_color();
}

void Cell_grid::update() {
    update_life();
    update_color();
}

void Cell_grid::update_life() {
    std::vector<Cell> rectangles_copy(rectangles);
    
    for (int j=0; j < m_squares; j++) {
        for (int i=0; i < n_squares; i++) {
            rectangles[j * n_squares + i].updateLife(rectangles_copy, i, j, m_squares, n_squares);
        }
    }
}

void Cell_grid::update_color() {
    for (int j=0; j < m_squares; j++) {
        for (int i=0; i < n_squares; i++) {
            rectangles[j * n_squares + i].updateColor();
        }
    }
}
