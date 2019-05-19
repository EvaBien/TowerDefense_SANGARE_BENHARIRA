#include <string>
#include "../include/Building.hpp"


using namespace std;

Building (BuildingType type){ // A COMPLETER NE FONCTION DU SUJET
    this->type=type;
    if (type==RADAR){
      this->m_portee=100;
      this->p_price=100;
    } else if (type==WEAPON){
      this->m_portee=75;
      this->p_price=75;
    } else{
      this->m_portee=50;
      this->p_price=50;
    }
}

//////////GETTERS//////////

int getPortee(){
    return this->m_gportee;
}


int getPrice(){
    return this->m_price;
}

TowerType getBuildingType(){
    return this->type;
}


/////////SETTERS//////////

void setPortee(int portee){
    this->m_portee =  portee;
}


void setPrice(int price){
    this->m_price =  price;
}

void setBuildingType(towerType){
    this->type = towerType;
}


//////////OTHER METHODS//////////

void afficher(){

}

bool isBuildable(){
    //à implémenter telle que renvoie true si constructible, false sinon
    //le tout en fonction d'une position déterminée grâce à entité ?
}

void upgradeTower(Tower t){
  if (this->getType()==RADAR){
    t.setPortee(t->getPortee()*(1,25));
  } else   if (this->getType()==WEAPON){
      t.setDamages(t->getDamages()*(1,25));
    } else {
        t.setCadence(t->getCadence()*(1,25));
    }
}
