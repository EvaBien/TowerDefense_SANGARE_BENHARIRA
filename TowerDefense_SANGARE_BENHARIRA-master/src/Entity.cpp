#include "Entity.hpp"

#include <string>

Entity::Entity(){}
Entity::Entity(float x, float y) {
  this->m_x=x;
  this->m_y=y;
}

Entity::~Entity(){}

//////////GETTERS/////////

float Entity::getX(){
  return this->m_x;
}

float Entity::getY(){
  return this->m_y;
}

Tile* Entity::getTile(){
  return this->m_tile;
}

std:: string  Entity::getAffichage(){
  return this->m_affichage;
}

///////////SETTERS////////

void Entity::setX(float x){
  this->m_x=x;
}

void Entity::setY(float y){
  this->m_y=y;
}

void Entity::setTile(Tile *t){
  this->m_tile=t;
}

void  Entity::setAffichage(std::string path){
  this->m_affichage=path;
}


////// OTHER ///////

float distance(float xA, float yA, float xB, float yB){
  float distanceX = pow(xA-xB,2);
  float distanceY = pow(yA-yB,2);

  return sqrt(distanceX+distanceY);
}

void  Entity::afficher(){}
