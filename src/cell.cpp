//
//  cell.cpp
//  my_first_sfml
//
//  Created by Arnau Jutglar Puig on 12/11/23.
//  Copyright © 2023 Arnau Jutglar Puig. All rights reserved.
//

#include "Cell.hpp"

Cell::Cell(sf::Vector2f v) : sf::RectangleShape(v) {
    if (rand() % 2 == 0) {is_alive = false;}
    else {is_alive = true;}
}


void Cell::updateColor() {
    if (is_alive) {
        setFillColor(sf::Color::White);
    } else {
        setFillColor(sf::Color::Black);
    }
}

void Cell::updateLife(std::vector<Cell>& ptr, int x_pos, int y_pos, int rows, int cols) {
    int alive=0;
    
    // Upper left corner
    if (x_pos == 0 && y_pos == 0) {
        for (int j = y_pos; j <= y_pos +1; j++) {
            for (int i = x_pos; i <= x_pos +1; i++) {
                if (j != y_pos || i != x_pos) {
                    // Check it only for the different cells.
                    if (ptr[j*cols + i].is_alive) {alive++;}
                }
            }
        }
        
        if (not is_alive && alive == 3) {is_alive = true;}
        else if ((is_alive && alive == 2) || (is_alive && alive == 3)) {is_alive = true;}
        else {is_alive = false;}
        
        return;
    }
    
    // Upper right corner
    if (x_pos == cols -1 && y_pos == 0) {
        for (int j = y_pos; j <= y_pos +1; j++) {
            for (int i = x_pos -1; i <= x_pos; i++) {
                if (j != y_pos || i != x_pos) {
                    // Check it only for the different cells.
                    if (ptr[j*cols + i].is_alive) {alive++;}
                }
            }
        }
        
        if (not is_alive && alive == 3) {is_alive = true;}
        else if ((is_alive && alive == 2) || (is_alive && alive == 3)) {is_alive = true;}
        else {is_alive = false;}
        
        return;

    }
    
    // Bottom left corner
    if (x_pos == 0 && y_pos == rows -1) {
        for (int j = y_pos -1; j <= y_pos; j++) {
            for (int i = x_pos; i <= x_pos +1; i++) {
                if (j != y_pos || i != x_pos) {
                    // Check it only for the different cells.
                    if (ptr[j*cols + i].is_alive) {alive++;}
                }
            }
        }
        
        if (not is_alive && alive == 3) {is_alive = true;}
        else if ((is_alive && alive == 2) || (is_alive && alive == 3)) {is_alive = true;}
        else {is_alive = false;}
        
        return;
    }
    
    // Bottom right corner
    if (x_pos == cols -1 && y_pos == rows -1) {
        for (int j = y_pos -1; j <= y_pos; j++) {
            for (int i = x_pos -1; i <= x_pos; i++) {
                if (j != y_pos || i != x_pos) {
                    // Check it only for the different cells.
                    if (ptr[j*cols + i].is_alive) {alive++;}
                }
            }
        }
        
        if (not is_alive && alive == 3) {is_alive = true;}
        else if ((is_alive && alive == 2) || (is_alive && alive == 3)) {is_alive = true;}
        else {is_alive = false;}
        
        return;
    }
    
    // Upper edge
    if (y_pos == 0) {
        for (int j = y_pos; j <= y_pos +1; j++) {
            for (int i = x_pos -1; i <= x_pos +1; i++) {
                if (j != y_pos || i != x_pos) {
                    // Check it only for the different cells.
                    if (ptr[j*cols + i].is_alive) {alive++;}
                }
            }
        }
        
        if (not is_alive && alive == 3) {is_alive = true;}
        else if ((is_alive && alive == 2) || (is_alive && alive == 3)) {is_alive = true;}
        else {is_alive = false;}
        
        return;
    }
    
    // Bottom edge
    if (y_pos == rows -1) {
        for (int j = y_pos -1; j <= y_pos; j++) {
            for (int i = x_pos -1; i <= x_pos +1 +1; i++) {
                if (j != y_pos || i != x_pos) {
                    // Check it only for the different cells.
                    if (ptr[j*cols + i].is_alive) {alive++;}
                }
            }
        }
        
        if (not is_alive && alive == 3) {is_alive = true;}
        else if ((is_alive && alive == 2) || (is_alive && alive == 3)) {is_alive = true;}
        else {is_alive = false;}
        
        return;
    }
    
    // Left edge
    if (x_pos == 0) {
        for (int j = y_pos -1; j <= y_pos +1; j++) {
            for (int i = x_pos; i <= x_pos +1; i++) {
                if (j != y_pos || i != x_pos) {
                    // Check it only for the different cells.
                    if (ptr[j*cols + i].is_alive) {alive++;}
                }
            }
        }
        
        if (not is_alive && alive == 3) {is_alive = true;}
        else if ((is_alive && alive == 2) || (is_alive && alive == 3)) {is_alive = true;}
        else {is_alive = false;}
        
        return;
    }
    
    // Right edge
    if (x_pos == cols -1) {
        for (int j = y_pos -1; j <= y_pos +1; j++) {
            for (int i = x_pos -1; i <= x_pos; i++) {
                if (j != y_pos || i != x_pos) {
                    // Check it only for the different cells.
                    if (ptr[j*cols + i].is_alive) {alive++;}
                }
            }
        }
        
        if (not is_alive && alive == 3) {is_alive = true;}
        else if ((is_alive && alive == 2) || (is_alive && alive == 3)) {is_alive = true;}
        else {is_alive = false;}
        
        return;
    }
    
    // Else: inner part
    for (int j = y_pos -1; j <= y_pos +1; j++) {
        for (int i = x_pos -1; i <= x_pos +1; i++) {
            if (j != y_pos || i != x_pos) {
                // Check it only for the different cells.
                if (ptr[j*cols + i].is_alive) {alive++;}
            }
        }
    }
    
    if (not is_alive && alive == 3) {is_alive = true;}
    else if ((is_alive && alive == 2) || (is_alive && alive == 3)) {is_alive = true;}
    else {is_alive = false;}
    
    return;
}
