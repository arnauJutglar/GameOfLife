//
//  square_grid.cpp
//  my_first_sfml
//
//  Created by Arnau Jutglar Puig on 12/11/23.
//  Copyright © 2023 Arnau Jutglar Puig. All rights reserved.
//

#include "Square_grid.hpp"

template class Square_grid<sf::RectangleShape>;
template Square_grid<sf::RectangleShape>::Square_grid(sf::RenderWindow&, int);

template class Square_grid<Cell>;
template Square_grid<Cell>::Square_grid(sf::RenderWindow&, int);


template <typename T>
Square_grid<T>::Square_grid(sf::RenderWindow& win, int c) : Grid<T>(win, win.getSize().y/c, win.getSize().x/c) {
}


