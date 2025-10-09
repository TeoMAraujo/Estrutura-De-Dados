SRC = src
OBJ = obj
BIN = bin
INC = include

SOURCES = $(wildcard $(SRC)/*.cpp)
SOURCES := $(filter-out $(SRC)/vector.cpp,$(SOURCES))
OBJECTS = $(patsubst $(SRC)/%.cpp,$(OBJ)/%.o,$(SOURCES))

CXX = gcc
CXXFLAGS = -I$(INC) -Wall -Wextra -std=c++11 -lstdc++

all: $(BIN)/tp1.out

$(OBJ)/%.o: $(SRC)/%.cpp | $(OBJ)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BIN)/tp1.out: $(OBJECTS) | $(BIN)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJ):
	mkdir -p $(OBJ)

$(BIN):
	mkdir -p $(BIN)

clean:
	rm -f $(OBJ)/*.o $(BIN)/tp1.out