CXX = g++
CXXFLAGS = -Wall -std=c++11 -Iinclude

SRC = src/main.cpp src/commands.cpp src/file_ops.cpp src/navigation.cpp src/search.cpp src/permissions.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = build/file_explorer

all: $(TARGET)

$(TARGET): $(OBJ)
	@mkdir -p build
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

clean:
	rm -rf $(OBJ) $(TARGET)

run: all
	./$(TARGET)
