# Nombre del archivo fuente sin extensión
FILE = main

# Compilador y flags
CXX = g++
CXXFLAGS = -Wall -std=c++17

# Ejecutable se llamará como el archivo fuente
EXEC = $(FILE).out

all: $(EXEC)
	./$(EXEC)

$(EXEC): $(FILE).cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -f *.out