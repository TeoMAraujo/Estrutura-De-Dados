CXX = g++
CXXFLAGS = -Iinclude -std=c++11
TARGET = bin/tp2.out
OBJDIR = obj
BINDIR = bin

# Lista de arquivos fonte
SOURCES = src/main.cpp src/Corrida.cpp src/Trecho.cpp src/Parada.cpp
OBJECTS = $(SOURCES:src/%.cpp=$(OBJDIR)/%.o)

all: $(TARGET)

# Regra para criar o executável
$(TARGET): $(OBJECTS)
	mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

# Regra padrão para compilar arquivos .cpp em .o
$(OBJDIR)/%.o: src/%.cpp
	mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJDIR)/*.o $(TARGET)

.PHONY: all clean