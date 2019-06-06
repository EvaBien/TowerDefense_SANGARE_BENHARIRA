#include "../include/tower.hpp"
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



Tower::Tower(float x, float y) : m_x(x), m_y(y), m_radius(60)
{
    printf("New tower created ! \n");
}

Tower::Tower(TowerType type,float x, float y) // AdType + Radius en fonction de portée
{
  this->m_x=x;
  this->m_y=y;
  this->m_type=type;
  if (this->m_type == RED_LASER){
    this->m_radius=120;
    printf("New Red Tower created ! \n");
  } else if (this->m_type == GREEN_GRASS){
    this->m_radius=100;
    printf("New Green Tower created ! \n");
  } else if (this->m_type == YELLOW_GAMMELLE){
    this->m_radius=100;
    printf("New Yellow Tower created ! \n");
  } else if (this->m_type == BLUE_MILK){
    this->m_radius=150;
    printf("New Blue Tower created ! \n");
  }
}

  Tower::~Tower() {
    printf("Tower destructed ! \n");
  }

  void Tower::update(const char path[]){

    // Draw collision circle
    float segments = 16.0f;
    float increment = 2.0f * M_PI / segments;
    float theta = 0.0f;

    glColor4f(0, 0, 0, 0.2);
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
    GLuint towerTexture;
    towerTexture = initTexture(path);

    // glClear(GL_COLOR_BUFFER_BIT);
    glColor4f(255, 255, 255, 1);
    glBindTexture(GL_TEXTURE_2D, towerTexture);
    glBegin(GL_QUADS);
    glTexCoord2f(0, 1); glVertex2f(x-25.0, y+25.0);   // bas gauche
    glTexCoord2f(1, 1); glVertex2f(x+25.0, y+25.0);    // bas droite
    glTexCoord2f(1, 0); glVertex2f(x+25.0, y-25.0);   // haut droite
    glTexCoord2f(0, 0); glVertex2f(x-25.0, y-25.0);    // haut gauche
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);


  }
