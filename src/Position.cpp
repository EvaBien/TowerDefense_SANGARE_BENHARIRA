#include <string>
#include "../include/Position.hpp"

using namespace stp;

    Position::Position(float X,float Y){
      this->m_X=X;
      this->m_Y=Y;
    } //constructeur

    Position::~Position(){}; // destructeur

//////////GETTERS/////////

      float Position::getX(){
        return this->m_X;
      }

      float Position::getY(){
        return this->m_Y;
      }

///////////SETTERS////////

      void Position::setX(float X){
        this->m_X=X;
      }

      void Position::setY(float Y){
        this->m_Y=Y;
      }

      void Position::setPosition(float X, float Y){
        this->m_X=X;
        this->m_Y=Y;
      }
  //////////OTHERS/////////////

      float Position::distance(Position p){
        float distanceX = pow(this->getX()-p.getX(),2);
        float distanceY = pow(this->getY()-p.getY(),2);

        return sqrt(distanceX+distanceY);
      }

    };

#endif
