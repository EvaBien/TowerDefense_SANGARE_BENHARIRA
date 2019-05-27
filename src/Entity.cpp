#include <string>
#include "../include/Entity.hpp"

using namespace std;

 Entity::Entity(string path) {
  this->m_position=position;
  this->m_string=path;
  this->m_x=X;
  this->m_y=Y;
}

 Entity::~Entity(){0;}

//////////GETTERS/////////

  float Entity::getX(){
    return this->m_X;
  }

  float Entity::getY(){
    return this->m_Y;
  }
  string  Entity::getAffichage(){
    return this->m_affichage;
  }

///////////SETTERS////////

  void Entity::setX(float X){
    this->m_X=X;
  }

  void Entity::setY(float Y){
    this->m_Y=Y;
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
