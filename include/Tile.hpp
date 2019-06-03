#pragma once

#include <string>
#include <math.h>
#include "Node.hpp"

enum ColorTile {
	EXIT,
	ENTRY,
	BUILD,
	PATH,
	NODE,
};

class Tile {
private:
  // Attributs
  float m_x; //jusqu'à quelle tile peut tirer
  float m_y; //prix de la tour
  int m_side;
  bool m_buildable;
  ColorTile m_color;

public:
  // Méthodes

  Tile();
  Tile(float x, float y, ColorTile color);
  ~Tile();

  /////GETTERS/////
  float getX();
  float getY();
  int getSide();
  bool getBuildable();
  ColorTile getType();

  /////SETTERS/////
  void setX(float x);
  void setY(float y);
  void setSide(float val);
  void setBuildable(bool val);
  void setType(ColorTile color);

  //////OTHERS//////

  float distance(Tile *t);

  // bool idBuildable();

};
