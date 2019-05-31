#include <string>
#include "../include/TextureController.hpp"
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>




bool isLoaded (SDL_Surface* image){
  if (image__NULL){
    printf("FAIL : Texture loading");
    SQL_Quit();
    return 0;
  }
  return 1;
}

GLuint setTexture(const char* filename){
  SDL_Surface *image = IMG_Load(filename);
  if (!isLoaded(image)){
    return 0;
  }

  GLuint textureId;

  glGenTexture(1, &textureId);
  glBindTexture(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);


  glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,image->w,image->h,0,GL_RGBA,GL_UNSIGNED_BYTE,image->pixels);

  glBinTexture(GL_TEXTURE_2D,0);
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
