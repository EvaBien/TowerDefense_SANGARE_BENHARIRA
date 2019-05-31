#include <string>
#include "../include/Building.hpp"
#include "../include/Game.hpp"
#include <GL/gl.h>

using namespace std;

Building::Building (BuildingType type, Tile *tile, Game *game){
  this->type=type;
  if (type==RADAR){
    this->m_portee=100;
    this->m_price=100;
    this->m_affichage = "../images/buildingRadar.png";
  } else if (type==WEAPON){
    this->m_portee=75;
    this->m_price=75;
    this->m_affichage = "../images/buildingWeapon.png";
  } else{
    this->m_portee=50;
    this->m_price=50;
    this->m_affichage = "../images/buildingStock.png";
  }
  this->m_tile=tile;
  this->m_x = tile->getX(); // Position de l'entrée de la map
  this->m_y = tile->getY(); // Position de l'entrée de la map
  this->m_tile->setBuildable(false);

}

//////////GETTERS//////////

Tile* Building::getTile(){
  return this->m_tile;
}

int Building::getPortee(){
  return this->m_portee;
}


int Building::getPrice(){
  return this->m_price;
}

BuildingType Building::getType(){
  return this->type;
}

Game* Building::getGame(){
  return this->game;
}
/////////SETTERS//////////

void Building::setTile(Tile *tile){
  this->m_tile=tile;
  this->setX(tile->getX());
  this->setY(tile->getY());
}

void Building::setPortee(int portee){
  this->m_portee =  portee;
}


void Building::setPrice(int price){
  this->m_price =  price;
}

void Building::setBuildingType(BuildingType type){
  this->type = type;
}

void Building::setGame(Game *game){
  this->game=game;
}


//////////OTHER METHODS//////////

void Building::afficher(){
  GLuint buildingTexture = 0;
  string pathBuilding = this->getAffichage();
  buildingTexture=loadTexture(pathBuilding);

  glPushMatrix();
  glTranslate(this->getTile()->getX(),this->getTile()->getY(),0);
  drawPicture(buildingTexture, 10, 10); // Taille tower
  glPopMatrix();
}


void Building::upgradeTower(Tower *t){
  if (this->getType()==RADAR){
    t->setPortee(t->getPortee()*(1,25));
  } else   if (this->getType()==WEAPON){
    t->setDamages(t->getDamages()*(1,25));
  } else {
    t->setCadence(t->getCadence()*(1,25));
  }
}
