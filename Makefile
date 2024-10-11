# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -I./Source/coding/Headers -I./Source/src/include

# SFML library path
SFML_LIB = -lsfml-window -lsfml-graphics -lsfml-system
LDFLAGS = -L"C:/Users/91768/Downloads/Pathfinding-Main/Pathfinding-Main/Source/src/lib"

# Directories
SRC_DIR = ./Source/coding
OBJ_DIR = ./obj
BIN_DIR = ./bin

# Source files
SRCS = $(SRC_DIR)/main.cpp \
       $(SRC_DIR)/Astar.cpp \
       $(SRC_DIR)/BFS.cpp \
       $(SRC_DIR)/Dijkstra.cpp \
       $(SRC_DIR)/DrawMap.cpp \
       $(SRC_DIR)/DrawText.cpp \
       $(SRC_DIR)/GetAdjacentCells.cpp \
       $(SRC_DIR)/GetCell.cpp \
       $(SRC_DIR)/GetMouseCell.cpp

# Object files
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Target executable
TARGET = $(BIN_DIR)/pathfinding

# Default target
.PHONY: all clean run
all: $(TARGET)

# Build target
$(TARGET): $(OBJS)
	@if not exist "$(BIN_DIR)" mkdir "$(BIN_DIR)"
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(LDFLAGS) $(SFML_LIB)

# Compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@if not exist "$(OBJ_DIR)" mkdir "$(OBJ_DIR)"
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean the build
clean:
	rm -rf "$(OBJ_DIR)" "$(BIN_DIR)"

# Run the executable
run: $(TARGET)
	./$(TARGET)
