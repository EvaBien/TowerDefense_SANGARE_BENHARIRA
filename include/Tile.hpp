#ifndef DEF_TILE
#define DEF_TILE

#include <string>
#include "Node.hpp"

enum ColorTile{
  OUT,
  IN,
  BUILD,
  PATH,
  NODE,
};


class Tile{
private:
  // Attributs
  float m_x; //jusqu'à quelle tile peut tirer
  float m_y; //prix de la tour
  int m_side;
  bool m_buildable;
  ColorTile m_color;

public:
  // Méthodes

  Tile(float x, float y, ColorTile color);
  ~Tile();

  /////GETTERS/////
  float getX();
  float getY();
  int getSide();
  bool getBuildable();

  /////SETTERS/////
  void setX(float x);
  void setY(float y);
  void setSide(float val);
  void setBuildable(bool val);

  //////OTHERS//////

  float distance(Tile c);

  // bool idBuildable();

};

#endif
