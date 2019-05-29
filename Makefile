# TowerDefense_SANGARE_BENHARIRA
# TowerDefense_SANGARE_BENHARIRA

# OUR MAKEFILE

#compilateur
#CC = gcc
CXX     = g++
#Variable Tower_defense
ITD = TowerDefense_SANGARE_BENHARIRA
#options de compilation
CPPFLAGS = -Wall -O2 -g 
#options de l'édition de lien
LDFLAGS	= -lSDL -lSDL_image -lGLU -lGL -lglut -lm

#liste des fichiers source du projet
SRC = $(shell find . -name "*.cpp")

#liste des includes, fichiers architecture du projet
INC = $(shell find . -name "*.hpp")

#liste des fichiers objet du projet
#substitue les .o aux .cpp pour ts les fichiers dans SRC lors de la recopie
#$(SRC) ou $(OBJ) ? ==> différent selon modèle = demander pk ?
OBJ = $(patsubst %.cpp, %.o, $(SRC)) 

# RM = rm -f
#pas utilisé pour l'instant mais pourrait l'être

all: $(ITD) #BUILD ALL THE EXECUTABLE

#créer les différents objets du projet
#lier les objets à leur fichiers sources ?

clean: #Remove all .o files
	@echo "**************************"
	@echo "CLEAN"
	@echo "**************************"
	rm -f $(OBJ)
	@echo "**************************"
	@echo ".o files are all removed"
	@echo "**************************"

BIGCLEAN: clean #Remove all "build artifacts" like .o files and the .exe
## ATTENTION ==> RISQUE DE TOUT EFFACER ?
	rm -f $(ITD)
	@echo "File .o and .exe are all removed"


