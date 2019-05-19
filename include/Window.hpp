#pragma once

#ifndef DEF_WINDOW
#define DEF_WINDOW

#include <cmath>
#include <stdlib.h>
#include <stdio.h>
#include <GL/glu.h>
#include <SDL2/SDL.h>



void init();
void reshape(SDL_Surface** surface, unsigned int width, unsigned int height);

/*****************************/
/********* COULEURS **********/
/*****************************/
typedef enum { // Va surement bouger
    RED,
    GREEN,
    BLUE,
} Couleur;

#endif
