<<<<<<< HEAD
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

=======
# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -g

# Target executable
TARGET = main

# Source files
SRCS = main.cpp automate.cpp lexer.cpp symbole.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default rule to build and run the executable
all: $(TARGET) run

# Default rule to build and run the executable
all: $(TARGET) run

# Rule to link object files into the target executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile .cpp files into .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to run the executable
run: $(TARGET)
	./$(TARGET)

# Clean rule to remove generated files
clean:
	rm -f $(TARGET) $(OBJS)
>>>>>>> 4a75819cea851b36f77992d21450c069a5356a8a
