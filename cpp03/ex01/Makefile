# Nom de l'exécutable
NAME = program

# Fichiers sources
SRC = main.cpp ClapTrap.cpp

# Fichier header
HEADERS = ClapTrap.hpp

# Flags de compilation
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Compilateur
CXX = c++

# Règle par défaut pour construire l'exécutable
all: $(NAME)

# Création de l'exécutable
$(NAME): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

# Nettoyage des fichiers objets et de l'exécutable
clean:
	rm -f $(NAME)

# Règle pour supprimer les fichiers temporaires ou objets
fclean: clean
	rm -f $(NAME)

# Règle pour recompiler tout
re: fclean all