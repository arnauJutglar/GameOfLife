main: src/grid.o src/square_grid.o src/cell.o src/cell_grid.o src/main.o Makefile
	g++ src/grid.o src/square_grid.o src/cell.o src/cell_grid.o src/main.o -o main -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

src/main.o: src/main.cpp Makefile
	g++ -c -Wall -std=c++11 src/main.cpp -o src/main.o -I SFML/include -L SFML/SFML-2.6.1-macOS-clang-64-bit/lib

src/grid.o: src/grid.cpp src/Grid.hpp Makefile
	g++ -c -Wall -std=c++11 src/grid.cpp -o src/grid.o -I SFML/include -L SFML/SFML-2.6.1-macOS-clang-64-bit/lib

src/square_grid.o: src/square_grid.cpp Makefile
	g++ -c -Wall -std=c++11 src/square_grid.cpp -o src/square_grid.o -I SFML/include -L SFML/SFML-2.6.1-macOS-clang-64-bit/lib

src/cell.o: src/cell.cpp src/Cell.hpp Makefile
	g++ -c -Wall -std=c++11 src/cell.cpp -o src/cell.o -I SFML/include -L SFML/SFML-2.6.1-macOS-clang-64-bit/lib

src/cell_grid.o: src/cell_grid.cpp src/Cell_grid.hpp Makefile
	g++ -c -Wall -std=c++11 src/cell_grid.cpp -o src/cell_grid.o -I SFML/include -L SFML/SFML-2.6.1-macOS-clang-64-bit/lib

clean:
	rm src/*.o ; rm main 
