#include <string>
#include "../include/Entity.hpp"

using namespace std;


  Entity::Entity(){}
  Entity::Entity(float x, float y) {
  this->m_x=x;
  this->m_y=y;
}

 Entity::~Entity(){0;}

//////////GETTERS/////////

  float Entity::getX(){
    return this->m_x;
  }

  float Entity::getY(){
    return this->m_y;
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
