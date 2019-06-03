#include "TextureController.hpp"

#include <string>
#include <stdio.h>
// #include <SDL/SDL_image.h>
#include <SDL2/SDL.h>
#include <glad/glad.h>
#include <GL/glu.h>

bool isLoaded (SDL_Surface* image){
  if (image == nullptr){
    printf("FAIL : Texture loading");
    return false;
  }
  return true;
}

GLuint loadTexture(const char* filename) {
	// TODO
	return 0;
}

GLuint setTexture(const char* filename){
  // SDL_Surface *image = IMG_Load(filename);
	SDL_Surface* image = nullptr;
  if (!isLoaded(image)){
    return 0;
  }

  GLuint textureId;

  glGenTextures(1, &textureId);
  glBindTexture(GL_TEXTURE_2D, textureId);


  // glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,image->w,image->h,0,GL_RGBA,GL_UNSIGNED_BYTE,image->pixels);

  glBindTexture(GL_TEXTURE_2D, 0);
  SDL_FreeSurface(image);

  return textureId;
}



void drawPicture(GLuint textureId, float x, float y){

  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D,textureId);
  glBegin(GL_QUADS);
  glTexCoord2f(0,1);
  glVertex2f(-x/2,-y/2);
  glTexCoord2f(1,1);
  glVertex2f(x/2,-y/2);
  glTexCoord2f(1,0);
  glVertex2f(x/2,y/2);
  glTexCoord2f(0,0);
  glVertex2f(-x/2,y/2);
  glEnd();
  glDisable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D,0);
}


// void freePicture(GLuint texture, SDL_Surface* picture){
//   SDL_FreeSurface(picture);
//   glBindTexture(GL_TEXTURE_2D,0);
// }
