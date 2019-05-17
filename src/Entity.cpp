#include <string>
#include "../include/Entity.hpp"

using namespace std;

Entity(float X,float Y,string path) {
  m_X=X;
  m_Y=Y;
  m_string=path;
}

//////////GETTERS/////////

  float getX(){
    return this->m_X;
  }
  float getY(){
    return this->m_Y;
  }
  string getAffichage(){
    return this->m_affichage;
  }

///////////SETTERS////////

  void setX(float X){
    this->m_X=X;
  }
  void setY(float Y){
    this->m_Y=Y;
  }
  void setAffichage(std::string path){
    this->m_affichage=path;
  }


  ////// OTHER ///////
  void afficher(){

  }
