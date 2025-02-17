# Nom de l'exécutable
TARGET = harl

# Fichiers sources
SRC = main.cpp Harl.cpp

# Fichiers d'en-tête
HEADERS = Harl.hpp

# Options de compilation
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Fichiers objets
OBJ = $(SRC:.cpp=.o)

# Règle par défaut
all: $(TARGET)

# Compilation de l'exécutable
$(TARGET): $(OBJ) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET)

# Compilation des fichiers objets
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Nettoyage
clean:
	rm -f $(OBJ)	

fclean: clean
	rm -f $(TARGET)

# Reconstruire tout
re: fclean all