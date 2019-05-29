#include <string>
#include "../include/Building.hpp"


using namespace std;

Building (BuildingType type, Case *case){ // A COMPLETER NE FONCTION DU SUJET
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
    this->m_case=*case;
    this->m_x = case->getX(); // Position de l'entrée de la map
    this->m_y = case->getY(); // Position de l'entrée de la map
}

//////////GETTERS//////////

Case Building::getCase(){
  return this->m_case;
}

int Building::getPortee(){
    return this->m_gportee;
}


int Building::getPrice(){
    return this->m_price;
}

TowerType Building::getBuildingType(){
    return this->type;
}

Game Building::getGame(){
  return this->game;
}
/////////SETTERS//////////

void Building::setCase(Case *case){
  this->m_case=case;
  this->setX(case->getX());
  this->setY(case->getY());
}

void Building::setPortee(int portee){
    this->m_portee =  portee;
}


void Building::setPrice(int price){
    this->m_price =  price;
}

void Building::setBuildingType(towerType type){
    this->type = type;
}

void Building::setGame(int *game){
  this->game=game;
}


//////////OTHER METHODS//////////

void Building::afficher(){
    GLuint buildingTexture = 0;
    string pathBuilding = this->getAffichage();
    buildingTexture=loadTexture(pathBuilding);

    glPushMatrix();
    glTranslate(this->getPosition()->getX(),this->getPosition()->getY(),0);
    drawPicture(buildingTexture, 10, 10); // Taille tower
    glPopMatrix();
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
