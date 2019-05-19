#include <string>
#include "../include/Building.hpp"


using namespace std;

Building (BuildingType type, Position p){ // A COMPLETER NE FONCTION DU SUJET
    this->type=type;
    if (type==RADAR){
      this->m_portee=100;
      this->p_price=100;
      this->m_affichage = "../images/buildingRadar.png";
    } else if (type==WEAPON){
      this->m_portee=75;
      this->p_price=75;
      this->m_affichage = "../images/buildingWeapon.png";
    } else{
      this->m_portee=50;
      this->p_price=50;
      this->m_affichage = "../images/buildingStock.png";
    }
    this->m_position= p; // Position de l'entrée de la map
}

//////////GETTERS//////////

int Building::getPortee(){
    return this->m_gportee;
}


int Building::getPrice(){
    return this->m_price;
}

TowerType Building::getBuildingType(){
    return this->type;
}

string Building::getAffichage(){
  return this->m_affichage;
}

/////////SETTERS//////////

void Building::setPortee(int portee){
    this->m_portee =  portee;
}


void Building::setPrice(int price){
    this->m_price =  price;
}

void Building::setBuildingType(towerType type){
    this->type = type;
}

void Building::setAffichage(string path){
  this->m_affichage=path;
}


//////////OTHER METHODS//////////

void Building::afficher(){

}

bool Building::isBuildable(){
    //à implémenter telle que renvoie true si constructible, false sinon
    //le tout en fonction d'une position déterminée grâce à entité ?
}

void Building::upgradeTower(Tower t){
  if (this->getType()==RADAR){
    t.setPortee(t->getPortee()*(1,25));
  } else   if (this->getType()==WEAPON){
      t.setDamages(t->getDamages()*(1,25));
    } else {
        t.setCadence(t->getCadence()*(1,25));
    }
}
