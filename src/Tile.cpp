#include "Tile.hpp"

using namespace std;

Tile::Tile(){

}
Tile::Tile(float x , float y, ColorTile color){
  this->m_x=x;
  this->m_y=y;
  this->m_side = 100;
  this->m_color=color;
  if (this->m_color!=BUILD){
    this->m_buildable=false;
  } else {
    this->m_buildable=true;
  }
}

  Tile::~Tile(){}

  /////GETTERS/////
  float Tile::getX(){
    return this->m_x;
  }

  float Tile::getY(){
    return this->m_y;
  }

  int Tile::getSide(){
    return this->m_side;
  }

  bool Tile::getBuildable(){
    return this->m_buildable;
  }

  ColorTile Tile::getType(){
    return this->m_color;
  }
  /////SETTERS/////
  void Tile::setX(float x){
    this->m_x=x;
  }

  void Tile::setY(float y){
    this->m_y=y;
  }
  void Tile::setSide(float val){
    this->m_side=val;
  }
  void Tile::setBuildable(bool val){
    this->m_buildable=val;
  }

  void Tile::setType(ColorTile color){
    this->m_color = color;
  }

  //////OTHERS//////

  float Tile::distance(Tile *t){
    return sqrt((pow(this->getX()-t.getX(),2))+(pow(this->getY()-t.getY(),2)));
  }
