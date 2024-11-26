objects = main.o shapes.o

main: $(objects)
	g++ $(objects) -o main

shapes.o: shapes.cpp shapes.hpp
main.o: main.cpp shapes.hpp

.PHONY: clean
clean:
	rm -f $(objects) main
