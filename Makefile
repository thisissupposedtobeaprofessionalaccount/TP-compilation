EXEC = tp-compilation

CXX = g++
CXXFLAGS = -Wall -std=c++11 -g

STATE_DIR = states

SRCS = $(wildcard *.cpp) $(wildcard $(STATE_DIR)/*.cpp)

OBJS = $(SRCS:.cpp=.o)

all: $(EXEC)

# Liaison des objets pour créer l'exécutable
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Règle générique pour compiler les fichiers .cpp en .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Nettoyage des fichiers objets et de l'exécutable
clean:
	rm -f $(OBJS) $(EXEC)

# Nettoyage complet
mrproper: clean
	rm -f $(EXEC)

# Déclaration des cibles qui ne sont pas des fichiers
.PHONY: all clean mrproper

