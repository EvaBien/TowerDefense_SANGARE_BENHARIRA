
#include "../include/building.hpp"
#include "../include/textures.hpp"
#include "../include/constants.hpp"

#ifdef _WIN32
#include <windows.h>
#endif
#define _USE_MATH_DEFINES
#include <cmath>

#include <stdio.h>
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <stb_image/stb_image.h>

Building::Building(float x, float y) : m_x(x),m_y(y), m_radius(100){
  printf("New Building Created ! \n");
}

Building::Building(BuildingType type, float x, float y)
{
  this->m_x=x;
  this->m_y=y;
  this->m_type=type;
  if (this->m_type == RADAR){
    this->m_radius=150;
    printf("New Radar Building created ! \n");
  } else if (this->m_type == WEAPON){
    this->m_radius=120;
    printf("New Weapon Building created ! \n");
  } else if (this->m_type == STOCK){
    this->m_radius=100;
    printf("New Stock Building created ! \n");
  }
}

Building::~Building() {
    printf("Building destructed ! \n");
}

void Building::update(const char path[]){


  // Draw collision circle
  float segments = 16.0f;
  float increment = 2.0f * M_PI / segments;
  float theta = 0.0f;

  glColor4f(255, 255, 255, 0.4);
  glBegin(GL_POLYGON);
  // glBegin(GL_LINE_LOOP);
  for (int i = 0; i < segments; i++) {
    float x = m_x + m_radius * cos(theta);
    float y = m_y + m_radius * sin(theta);
    glVertex2f(x, y);
    theta += increment;
  }
  glEnd();

  ////// CHARGER TEXTURE /////
  float x = this->getX();
  float y = this->getY();
  GLuint buildingTexture;
  buildingTexture = initTexture(path);

  // glClear(GL_COLOR_BUFFER_BIT);
  glColor4f(255, 255, 255, 1);
  glBindTexture(GL_TEXTURE_2D, buildingTexture);
  glBegin(GL_QUADS);
  glTexCoord2f(0, 1); glVertex2f(x-30.0, y+30.0);   // bas gauche
  glTexCoord2f(1, 1); glVertex2f(x+30.0, y+30.0);    // bas droite
  glTexCoord2f(1, 0); glVertex2f(x+30.0, y-30.0);   // haut droite
  glTexCoord2f(0, 0); glVertex2f(x-30.0, y-30.0);    // haut gauche
  glEnd();
  glBindTexture(GL_TEXTURE_2D, 0);

}
