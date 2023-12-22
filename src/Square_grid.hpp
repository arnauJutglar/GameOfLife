//
//  Square_grid.hpp
//  my_first_sfml
//
//  Created by Arnau Jutglar Puig on 12/11/23.
//  Copyright © 2023 Arnau Jutglar Puig. All rights reserved.
//

#ifndef Square_grid_h
#define Square_grid_h

#include <SFML/Graphics.hpp>

#include "Grid.hpp"
#include "Cell.hpp"

template <typename T>
class Square_grid : public Grid<T> {
private:
public:
    /// Builds a grid of squares where each side has the specified size.
    /// - Parameter int The side size.
    Square_grid(sf::RenderWindow&, int);
};


#endif /* Square_grid_h */
