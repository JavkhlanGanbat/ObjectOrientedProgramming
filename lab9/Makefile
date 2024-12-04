# Compiler and Flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iheaders

# Directories
SRC_DIR = def
OBJ_DIR = obj
BIN_DIR = bin

# Source and Object Files
SOURCES = $(wildcard $(SRC_DIR)/*.cpp) main.cpp
OBJECTS = $(SOURCES:%.cpp=$(OBJ_DIR)/%.o)
EXECUTABLE = $(BIN_DIR)/main

# Rules
all: $(EXECUTABLE)

# Link all object files into the final executable
$(EXECUTABLE): $(OBJECTS)
	mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile each source file into an object file
$(OBJ_DIR)/%.o: %.cpp
	mkdir -p $(dir $@)  # Create necessary subdirectories under obj/
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean the build
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
