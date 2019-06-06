#pragma once

#include <glad/glad.h>
#include <SDL2/SDL.h>

bool isLoaded (SDL_Surface* image);

GLuint loadTexture(const char* filename);

void drawPicture(GLuint textureId, float x, float y); // AL

// void free_image(GLuint textureId, SDL_Surface* img); //CL
