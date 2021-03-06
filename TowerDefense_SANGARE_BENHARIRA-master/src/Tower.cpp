#include "Tower.hpp"

#include <string>
#include <glad/glad.h>

#include "Game.hpp"

/* Nombre minimal de millisecondes separant le rendu de deux images */
static const int FRAMERATE_MILLISECONDS = 1000 / 60;
using namespace std;

Tower::Tower (TowerType type, Tile *tile, Game *game){ //on considère 100 comme valeur neutre
  if (this->type == RED_LASER){
    this->m_damages = 150; //bcp de dégâts
    this->m_portee = 100;
    this->m_cadence = 150; //cadence faible
    this->m_price = 100;
    this->m_affichage = "images/towerRed.png";
  } else if (this->type == GREEN_GRASS) {
    this->m_damages = 100; // dégâts moyens
    this->m_portee = 50; //faible portée
    this->m_cadence = 25; //tirent très rapidement
    this->m_price = 100;
    this->m_affichage = "images/towerGreen.png";

  } else if (type == YELLOW_GAMMELLE) { //tirents sur tous les ennemis à leur portée
    this->m_damages = 50; //peu de dégâts
    this->m_portee = 50; //portée très limitée
    this->m_cadence = 50; //bonne cadence de tir
    this->m_price = 100;
    this->m_affichage = "images/towerYellow.png";

  } else { // ie BLUE_MILK
    this->m_damages = 50; //peu de dégâts
    this->m_portee =150 ; //bonne portée
    this->m_cadence = 50; //bonne cadence de tir
    this->m_price = 100;
    this->m_affichage = "images/towerBlue.png";
  }
  this->m_tile= tile;
  this->m_x = tile->getX(); // Position de l'entrée de la map
  this->m_y = tile->getY(); // Position de l'entrée de la map
  this->m_tile->setBuildable(false);
  this->target=nullptr;
  this->game=game;
}

//////////GETTERS//////////

Tile* Tower::getTile(){
  return this->m_tile;
}

int Tower::getDamages(){
  return this->m_damages;
}

int Tower::getPortee(){
  return this->m_portee;
}

int Tower::getCadence(){
  return this->m_cadence;
}

int Tower::getPrice(){
  return this->m_price;
}

TowerType Tower::getTowerType(){
  return this->type;
}

CatMonster* Tower::getTarget(){
  return this->target;
}

Game* Tower::getGame(){
  return this->game;
}
/////////SETTERS//////////

void Tower::setTile(Tile *tile){
  this->m_tile=tile;
  this->setX(tile->getX());
  this->setY(tile->getY());
}

void Tower::setDamages(int damages){
  this->m_damages =  damages; //Remplace valeur damages par une nouvelle
}

void Tower::setPortee(int portee){
  this->m_portee =  portee;
}

void Tower::setCadence(int cadence){
  this->m_cadence =  cadence;
}

void Tower::setPrice(int price){
  this->m_price =  price;
}

void Tower::setTowerType(TowerType type){
  this->type = type;
}

void Tower::setTarget(CatMonster *target){
  this->target=target;
}

void Tower::setGame(Game *game){
  this->game=game;
}

//////////OTHER METHODS//////////

void Tower::afficher(){
  GLuint towerTexture = 0;
  std::string pathTower = this->getAffichage();
  towerTexture=loadTexture(pathTower.c_str());

  glPushMatrix();
  // glTranslated(this->getPosition()->getX(),this->getPosition()->getY(),0);
  drawPicture(towerTexture, 60, 60); // Taille tower
  glPopMatrix();
}

void Tower::attack(){
  Uint32 startTime = SDL_GetTicks();
  while(this->getGame()->getFinish()==true){
    /* Calcul du temps ecoule */
    Uint32 elapsedTime = SDL_GetTicks() - startTime;
    /* Si trop peu de temps s'est ecoule, on met en pause le programme */
    if(elapsedTime < FRAMERATE_MILLISECONDS)
    {
      SDL_Delay(FRAMERATE_MILLISECONDS - elapsedTime);
    }

    if (elapsedTime>=this->getCadence()*10){ // Toutes les 10 secondes

      while(this->getTarget()==nullptr){
        this->searchTarget();
      }
      printf("TIIIIR !! ");
      this->getTarget()->beDamaged(this->getDamages(), this);
      startTime = SDL_GetTicks();
    }
  }
}

void Tower::searchTarget() {
	int portee = this->getPortee();
	float distanceMin = portee;
	CatMonster* catClosest = nullptr;
	Game* game = this->getGame();

	for (CatMonster* cat : game->getVecCat()) {
		Tile* cTile = cat->getTile();
		float distanceCurrent = cTile->distance(this->getTile());
		if (distanceCurrent < distanceMin) {
			distanceMin = distanceCurrent;
			catClosest = cat;
		}
		this->setTarget(catClosest);
	}
}