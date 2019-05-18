#include <string>
#include "../include/Entity.hpp"

using namespace std;

 Entity::Entity(Position position,string path) {
  this->m_position=position;
  this->m_string=path;
}

 Entity::~Entity(){0;}

//////////GETTERS/////////

  Position  Entity::getPosition(){
    return this->m_position;
  }
  string  Entity::getAffichage(){
    return this->m_affichage;
  }

///////////SETTERS////////

  void  Entity::setPosition(Position p){
    this->m_position=p;
  }
  void  Entity::setAffichage(std::string path){
    this->m_affichage=path;
  }


  ////// OTHER ///////
  void  Entity::afficher(){}
