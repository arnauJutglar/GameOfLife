//
//  grid.cpp
//  my_first_sfml
//
//  Created by Arnau Jutglar Puig on 12/11/23.
//  Copyright © 2023 Arnau Jutglar Puig. All rights reserved.
//

#include "Grid.hpp"

template class Grid<sf::RectangleShape>;
template Grid<sf::RectangleShape>::Grid(sf::RenderWindow&, int, int);
template Grid<sf::RectangleShape>::Grid(int, int, int, int);
template void Grid<sf::RectangleShape>::draw();
template void Grid<sf::RectangleShape>::setChessFill();

template class Grid<Cell>;
template Grid<Cell>::Grid(sf::RenderWindow&, int, int);
template Grid<Cell>::Grid(int, int, int, int);
template void Grid<Cell>::draw();
template void Grid<Cell>::setChessFill();



/*Grid::Grid(int m, int n, int l, int w) : m_squares(m), n_squares(n) {
    int a, b;
    a = l / m;
    b = w / n;
    for (int j=0; j < m; j++) {
        for (int i=0; i < n; i++) {
            rectangles.push_back(sf::RectangleShape(sf::Vector2f(a,b)));
            rectangles[j * m + i].setPosition(i*a, j*b);
            
            if ( ( (j % 2 == 0) && (i % 2 == 0) ) || ( (j % 2 == 1) && (i % 2 == 1) ) ) {
                rectangles[j * m + i].setFillColor(sf::Color::White);
            } else {
                rectangles[j * m + i].setFillColor(sf::Color::Black);
            }
        }
    }
    

}

Grid::Grid(sf::RenderWindow& win, int m, int n) : Grid(m, n, win.getSize().x, win.getSize().y) {
    window = &win;
}

void Grid::draw() {
    for (int i=0; i < m_squares * n_squares; i++) {
        window->draw(rectangles[i]);
    }
}*/

template <typename T>
Grid<T>::Grid(int m, int n, int l, int w) : m_squares(m), n_squares(n) {
    int a, b;
    a = w / m;
    b = l / n;
    for (int j=0; j < m; j++) {
        for (int i=0; i < n; i++) {
            rectangles.push_back(T(sf::Vector2f(a,b)));
            rectangles[j * n + i].setPosition(i*a, j*b);
            
        }
    }
}

template <typename T>
Grid<T>::Grid(sf::RenderWindow& win, int m, int n) : Grid<T>(m, n, win.getSize().x, win.getSize().y) {
    window = &win;
}

template <typename T>
void Grid<T>::draw() {
    for (int i=0; i < m_squares * n_squares; i++) {
        window->draw(rectangles[i]);
    }
}

template <typename T>
void Grid<T>::setChessFill() {
    for (int j=0; j < m_squares; j++) {
        for (int i=0; i < n_squares; i++) {
            if ( ( (j % 2 == 0) && (i % 2 == 0) ) || ( (j % 2 == 1) && (i % 2 == 1) ) ) {
                rectangles[j * m_squares + i].setFillColor(sf::Color::White);
            } else {
                rectangles[j * m_squares + i].setFillColor(sf::Color::Black);
            }
        }
    }
}


