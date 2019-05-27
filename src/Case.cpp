#include "Case.hpp"

using namespace std;


  Case::Case(float x , float y, ColorCase color){
    this->m_x=x;
    this->m_y=y;
    this->m_side = 30;
    this->m_color=color;
if (this->m_color!=BUILD){
    this->m_buildable=false;
  } else {
    this->m_buildable=true;
  }

  Case::~Case(){0;}

    // Méthodes


    /////GETTERS/////
    float Case::getX(){
      return this->m_x;
    }

    float Case::getY(){
      return this->m_y;
    }

    int Case::getSide(){
      return this->m_side;
    }

    bool Case::getBuidable(){
      return this->m_buildable;
    }

    /////SETTERS/////
    void Case::setX(float x){
      this->m_x=x;
    }

    void Case::setY(float y){
      this->m_y=y;
    }
    void setSide(float val){
      this->m_side=val;
    }
    void setBuildable(bool val){
      this->m_buildable=val;
    }

    //////OTHERS//////


    // bool idBuildable(){
    //   // Différent de getBuildable ?
    // }

};

#endif
