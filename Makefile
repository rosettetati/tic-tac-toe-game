# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -std=c++17

# Executable name
TARGET = tictactoe

# Source files
SRCS = main.cpp game.cpp

# Object files
OBJS = main.o game.o

# Default target
.PHONY: all
all: $(TARGET)

# Build the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile main.cpp
main.o: main.cpp game.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

# Compile game.cpp
game.o: game.cpp game.h
	$(CXX) $(CXXFLAGS) -c game.cpp -o game.o

# Run the program
.PHONY: run
run: $(TARGET)
	./$(TARGET)

# Clean build files
.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)
