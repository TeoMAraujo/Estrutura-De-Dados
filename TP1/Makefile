SRC = src
OBJ = obj
BIN = bin
INC = include

SOURCES = $(wildcard $(SRC)/*.cpp)
SOURCES := $(filter-out $(SRC)/vector.cpp,$(SOURCES))
OBJECTS = $(patsubst $(SRC)/%.cpp,$(OBJ)/%.o,$(SOURCES))

CXX = g++
CXXFLAGS = -I$(INC) -Wall -Wextra -std=c++11

all: $(BIN)/tp1.out

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BIN)/tp1.out: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(OBJ)/*.o $(BIN)/tp1.out