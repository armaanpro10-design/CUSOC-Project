# Compiler settings
CXX = g++
CXXFLAGS = -Wall -std=c++17

# Target executable name
TARGET = todo_app

# Source files
SRCS = src/main.cpp src/TodoManager.cpp

# Default rule to build the project
all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

# Rule to clean up compiled files
clean:
	rm -f $(TARGET) tasks.txt