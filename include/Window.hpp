#pragma once

#ifndef DEF_WINDOW
#define DEF_WINDOW

#include <cmath>
#include <stdlib.h>
#include <stdio.h>
#include <GL/glu.h>
#include <SDL2/SDL.h>

/*****************************/
/********* FENETRE **********/
/*****************************/

/* Initialisation + Nom fenêtre*/
static const unsigned int WINDOW_WIDTH = 1000;
static const unsigned int WINDOW_HEIGHT = 700;
static const char WINDOW_TITLE[] = "Jeudicat";


/* Espace fenetre virtuelle */
// static const float GL_VIEW_WIDTH = 1200;
// static const float GL_VIEW_HEIGHT = 800;
static const float GL_VIEW_SIZE = 150.;


/* Nombre de bits par pixel de la fenetre */
static const unsigned int BIT_PER_PIXEL = 32;

/* Nombre minimal de millisecondes separant le rendu de deux images */
static const Uint32 FRAMERATE_MILLISECONDS = 1000 / 60;

void init();
void reshape(SDL_Surface** surface, unsigned int width, unsigned int height);

/*****************************/
/********* COULEURS **********/
/*****************************/
typedef enum {
    RED,
    GREEN,
    BLUE,
} Couleur;

#endif
