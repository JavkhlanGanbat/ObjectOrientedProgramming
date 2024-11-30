objects = main.o shapes.o

main: $(objects)
	g++ $(objects) -o main

shapes.o: shapes.cpp shapes.hpp
	g++ -c shapes.cpp -o shapes.o

main.o: main.cpp shapes.hpp
	g++ -c main.cpp -o main.o

.PHONY: clean
clean:
	rm -f $(objects) main

