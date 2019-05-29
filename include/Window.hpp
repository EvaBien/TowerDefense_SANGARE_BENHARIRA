#pragma once

#ifndef DEF_WINDOW
#define DEF_WINDOW

#include <cmath>
#include <stdlib.h>
#include <stdio.h>
#include <GL/glu.h>
#include <SDL2/SDL.h>
#include <glad/glad.h>
#include <spdlog/spdlog.h>



void initWindow();
void reshape(SDL_Surface** surface, unsigned int width, unsigned int height);


#endif
