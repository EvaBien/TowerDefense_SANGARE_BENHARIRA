#pragma once

#include <SDL2/SDL.h>

SDL_Window* initWindow();
void reshape(SDL_Surface** surface, unsigned int width, unsigned int height);
