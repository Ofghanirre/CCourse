# Ce makefile est un exemple détaillé comportant des règles génériques et variables automatiques
# il part du principe que votre projet a la structure suivante:
# ./src/ contient les fichiers .c
# ./inc/ contient les fichiers .h
#
# ================================================================
# VARIABLES
# ================================================================
# Nom de l'exécutable
TARGET = C_DOT_TREE_VISUALIZER

# Compilateur
CC = gcc

# Options de compilation
CFLAGS = -Wall -Wextra -Werror

# Répertoires
SRC_DIR = src
INC_DIR = inc
BUILD_DIR = build

# Fichiers sources et objets
# ici : écrire les sources à compiler
SRCS = $(SRC_DIR)/examples/binary_tree_example.c \
	   $(SRC_DIR)/examples/unary_tree_example.c \
	   $(SRC_DIR)/examples/ternary_tree_example.c \
	   $(SRC_DIR)/examples/binary_tree_only_data_example.c \
       $(SRC_DIR)/tree_display.c \
       $(SRC_DIR)/main.c


# Génération des noms des objets à obtenir
# "./src/fichier_x.c" devient "./build/fichier_x.o"
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

# ================================================================
# REGLES
# ================================================================

# Règle principale
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -I$(INC_DIR) $^ -o $@

# Compilation des fichiers sources en objets dans build/
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Création du dossier build s'il n'existe pas
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)
	mkdir -p $(BUILD_DIR)/examples

# Nettoyage
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

# Indique que ces cibles ne sont pas des fichiers
.PHONY: clean


# ================================================================
# VARIABLES AUTOMATIQUES EN MAKEFILE
# ================================================================
# Make utilise plusieurs variables automatiques utiles pour simplifier l'écriture des règles :
#
# $@  : Nom de la cible en cours de compilation (ex: l'exécutable final).
# $<  : Premier élément de la liste des dépendances (utile pour compiler un fichier source en objet).
# $^  : Liste complète des dépendances (utile pour la phase d'édition des liens).
# $*  : Nom du fichier sans extension (ex: si cible "build/main.o", alors $* = "build/main").
#
# Exemple d'utilisation :
# $(TARGET): $(OBJS)
#     $(CC) $(CFLAGS) -o $@ $^  # Remplace $(TARGET) et $(OBJS)
#
# $(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
#     $(CC) $(CFLAGS) -c $< -o $@  # Remplace $(SRC_DIR)/fichier.c et $(BUILD_DIR)/fichier.o
#
# Ces variables permettent d'écrire des règles génériques et réutilisables !
# Au lieu de devoir écrire une règle par fichiers / modules au comportement identique.
# ================================================================
