//
//  Grid.hpp
//  my_first_sfml
//
//  Created by Arnau Jutglar Puig on 12/11/23.
//  Copyright © 2023 Arnau Jutglar Puig. All rights reserved.
//

#ifndef Grid_h
#define Grid_h

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Cell.hpp"

/*class Grid {
private:
    std::vector<sf::RectangleShape> rectangles;
    sf::RenderWindow* window = nullptr;
    int m_squares;
    int n_squares;
    Grid(int, int, int, int);
public:
    /// Grid constructor.
    /// - Parameter sf::RenderWindow& the window where it will be drawn.
    /// - Parameter int Number of rows of the grid.
    /// - Parameter int Number of columns of the grid.
    Grid(sf::RenderWindow&, int, int);
    /// Draws the grid in the before given window.
    void draw();
};*/

template <typename T>
class Grid {
private:
    sf::RenderWindow* window = nullptr;
    Grid(int, int, int, int);
protected:
    std::vector<T> rectangles;
    int m_squares;
    int n_squares;
public:
    /// Grid constructor.
    /// - Parameter sf::RenderWindow& the window where it will be drawn.
    /// - Parameter int Number of rows of the grid.
    /// - Parameter int Number of columns of the grid.
    Grid(sf::RenderWindow&, int, int);
    /// Draws the grid in the before given window.
    void draw();
    void setChessFill();
};



#endif /* Grid_h */
