# compiler
CXX = g++


CXXFLAGS = -Wall -I./src


SRC = main.cpp src/Graph/Graph.cpp src/Algorithms.cpp datastructures/Queue.cpp datastructures/Stack.cpp

# Nom de l'exécutable
EXEC = myProg

# Règle par défaut
all: $(EXEC)

# Comment construire l'exécutable
$(EXEC): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $(SRC)

# Nettoyage
clean:
	rm -f $(EXEC)
