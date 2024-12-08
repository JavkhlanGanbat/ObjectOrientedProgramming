CXX = g++
CXXFLAGS = -std=c++20 -Wall -g

TARGET = lab10

SRC = main.cpp List.cpp shapes.cpp
OBJ = $(SRC:.cpp=.o)

DEPS = List.hpp shapes.hpp

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
