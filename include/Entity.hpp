#ifndef DEF_ENTITY
#define DEF_ENTITY

#include <string>
#include <cmath>
#include "Tile.hpp"
#include "Texture.hpp"
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>

class Entity{
protected:

  // Position position;
  float m_x;
  float m_y;
  std::string m_affichage;

public:

  Entity();
  Entity(float x, float y);
  ~Entity();


  //////////GETTERS/////////

  float getX();
  float getY();
  std::string getAffichage();

  ///////////SETTERS////////

  void setX(float X);
  void setY(float Y);
  void setAffichage(std::string path);

  //////////OTHERS/////////////

  float distance(float xA, float yA, float xB, float yB);
  virtual void afficher()=0;

};

#endif
