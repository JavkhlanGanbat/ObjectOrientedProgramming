CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

TARGET = program

SRCS = main.cpp Person.cpp Spouse.cpp Child.cpp Division.cpp JobDescription.cpp Employee.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

rebuild: clean all
