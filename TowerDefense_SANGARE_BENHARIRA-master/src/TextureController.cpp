// #include "../include/TextureController.hpp"
//
// #include <string>
// #include <stdio.h>
// #include <SDL/SDL_image.h>
// #include <stb_image/stb_image.h>
// #include <SDL2/SDL.h>
// #include <glad/glad.h>
// #include <GL/glu.h>
//
// void EnableTransparency()
// {
//   glEnable(GL_BLEND);
//   glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
// }
//
// GLuint LoadTexture(char *filename, int textw, int texth) {
//
//   SDL_Surface *surface;
//   GLuint textureid;
//   int mode;
//
//   surface = IMG_Load(filename);
//   if (!surface) {
//     return 0;
//   }
//
//   // work out what format to tell glTexImage2D to use...
//   if (surface->format->BytesPerPixel == 3) { // RGB 24bit
//     mode = GL_RGB;
//   } else if (surface->format->BytesPerPixel == 4) { // RGBA 32bit
//     mode = GL_RGBA;
//   } else {
//
//     SDL_FreeSurface(surface);
//     return 0;
//   }
//
//   textw=surface->w;
//   texth=surface->h;
//   // create one texture name
//   glGenTextures(1, &textureid);
//   // tell opengl to use the generated texture name
//   glBindTexture(GL_TEXTURE_2D, textureid);
//   // this reads from the sdl surface and puts it into an opengl texture
//   glTexImage2D(GL_TEXTURE_2D, 0, mode, surface->w, surface->h, 0, mode, GL_UNSIGNED_BYTE, surface->pixels);
//   // these affect how this texture is drawn later on...
//   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
//   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
//
//   // clean up
//   SDL_FreeSurface(surface);
//
//   return textureid;
// }
//
// void DrawTexture(int x, int y, GLuint textureid, int textw,int texth) {
//
//   //int textw,texth;
//   // tell opengl to use the generated texture name
//   glBindTexture(GL_TEXTURE_2D, textureid);
//   glEnable(GL_TEXTURE_2D);
//
//   // make a rectangle
//   glBegin(GL_QUADS);
//
//   // top left
//   glTexCoord2i(0, 0);
//   glVertex3f(x, y, 0);
//
//   // top right
//   glTexCoord2i(1, 0);
//   glVertex3f(x+textw, y, 0);
//
//   // bottom right
//   glTexCoord2i(1, 1);
//   glVertex3f(x+textw, y+texth, 0);
//
//   // bottom left
//   glTexCoord2i(0, 1);
//   glVertex3f(x, y+texth, 0);
//
//   glEnd();
//
//   glDisable(GL_TEXTURE_2D );
// }
