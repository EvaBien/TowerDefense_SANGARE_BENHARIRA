#include <string>
#include "../include/Game.hpp"
#include "../include/CatMonster.hpp"
#include "../include/Tower.hpp"
#include "../include/Building.hpp"
/* Nombre minimal de millisecondes separant le rendu de deux images */
static const Uint32 FRAMERATE_MILLISECONDS = 1000 / 60;
using namespace std;

Game() {
    this->m_cagnotte = 100;
    this->m_nbWave = 0;
    this->m_finished = false;
    this->m_map;
    this->m_time=0;
    // Initialiser 3 vecteurs

    this->m_monsters = std::vector<CatMonster*> monsters;
    this->m_towers = std::vector<Tower*> towers;
    this->m_buildings = std::vector<Building*> buildings;
}

//////////GETTERS//////////

int Game::getCagnotte(){
    return this->m_cagnotte;
}

int Game::getWave(){
    return this->m_nbWave;
}

bool Game::getFinish(){
    return this->m_finished;
}

Map Game::getMap(){
  return this->m_map;
}

int Game::getTime(){
  return this->m_time;
}

std::vector<CatMonster*> Game::getVecCat(){
  return this->m_monsters;
}

std::vector<Tower*> Game::getVecTower(){
  return this->m_towers;
}

std::vector<Building*> Game::getVecBuilding(){
  return this->m_buildings;
}

/////////SETTERS//////////


void Game::setCagnotte(int money){
  this->m_cagnotte=money;
}

void Game::setWave(int nbWave){
    this->m_nbWave=nbWave;
}

void Game::setFinish(bool value){
    this->m_finished = value;
}

void Game:setMap(Map map){
  this->m_map=map;
}

void Game:setTime(int time){
  this->m_time=time;
}

void Game::setAddVecCat(CatMonster* cat){
  this->m_monsters.push_back(cat);
}
void Game::setAddVecTower(Tower* tower){
  this->m_towers.push_back(tower);
}
void Game::setAddVecBuilding(Building* building){
  this->m_buildings.push_back(building);
}

// void Game::setDeleteVecCat(CatMonster* cat){
//  for (CatMonster* current : this->getVecCat()){
//    if (current === cat) {
//      delete cat;
//    }
//  }
// }
// void Game::setDeleteVecTower(Tower* tower){
//   this->m_towers.push_back(tower);
// }
// void Game::setDeleteVecBuilding(Building* building){
//   this->m_buildings.push_back(building);
// }

//////////OTHER METHODS//////////

void Game::startGame(){


  Map myMap = new Map();
  myMap->initMap();
  this->setMap(myMap);

  PathNode list = myMap->getListNodes();
  Case entry = list->getHead()->getCase();
  Case exit = list->getEnd()->getCase();

  this.setFinish(false);
  this.setTime(0);
  int nbWave = 0;
  while (this->getFinish()==false){


    /* Echange du front et du back buffer : mise a jour de la fenetre */
      SDL_GL_SwapBuffers();

      this->setWave(nbWave++);
      if ((this->getTime()%(60*90)==0)){ // SI ca fait 1min30sec
        prepareWave(this->getWave());
        this.setTime(0);

        if(this->getWave()>=20){
          this->gameOver();
        }
      }
      this.setTime(this.getTime()++);
  }
}

void Game::prepareWave(int numWave){
  // faire un pourcentage d'apparition des monstres en fonction du num Wave !
  int nbKitten = 2; // A modifier --> Décroissant en fonction du num Wave
  int nbJustCat = 6; // A modifier --> Croissant " "
  int nbFatCat = 10-(nbKitten+nbJustCat); // Ce qui reste, mais doit être croissant aussi...
// Avec un random ?

  for (int i=1; i<=nbKitten; i++){
    CatMonster* newKitten = new CatMonster(KITTEN,&this, entry);
    this->setAddVecCat(newKitten);
    newKitten->afficher();
  }
  for (int i=1; i<=nbJustCat; i++){
    CatMonster* newJustCat = new CatMonster(JUSTCAT,&this, entry);
    this->setAddVecCat(newJustCat);
    newJustCat->afficher();
  }
  for (int i=1; i<=nbFatCat; i++){
    CatMonster* newFatCat = new CatMonster(FATCAT,&this, entry);
    this->setAddVecCat(newFatCat);
    newFatCat->afficher();
  }
}

bool Game::canBuyTower(TowerType type){
  if (type== RED_LASER){
    int price = 100;
  } else if (type==GREEN_GRASS){
    int price = 100;
  } else if (type==YELLOW_GAMMELLE){
    int price = 100;
  } else {
    int price = 100;
  }
    if (this->m_cagnotte-price >=0){
      this.setCagnotte(this->m_cagnotte-price);
      return true;
    }
    return false;
}

bool Game::canBuyBuilding(BuildingType type){ // A modifier avec les noms des type de building
  if (type== RADAR){
    int price = 100;
  } else if (type==WEAPON){
    int price = 100;
  } else {
    int price = 100;
  }
    if (this->m_cagnotte-price >=0){
      this.setCagnotte(this->m_cagnotte-price);
      return true;
    }
    return false;
}

bool Game::canBuildBuilding(BuildingType type, Case *c){

}

bool Game::canBuildTower(TowerType type, Case c){

}

void Game::checkTowers(Building *b){
  int portee = b->getPortee();

  for (Tower* tower : this->getVecTower()){
      Case tCase = tower->getCase();
      float distance = tCase->distance(b->getCase());
        if (distance <= portee){
          b->upgradeTower(tower);
        }
}

void Game::checkBuildings(Tower *t){

  for (Building* building : this->getVecBuilding()){
    int portee = building->getPortee();
    Case bCase = building->getCase();
        float distance = bCase->distance(t->getCase());
        if (distance <= portee){
          building->upgradeTower(t);
        }
  }

void Game::constructTower(TowerType type, float x, float y){
  // Trouver la case c pour x;y
  if(this->canBuyTower()){
    if (this->canBuildTower(type, c)){
      tower = new Tower(type, c, &this);
      this->setAddVecTower(tower);
      this->checkBuilding();
      tower->afficher();
      tower->attack();
    } else {
      printf("NOT BUILDABLE ZONE");
    }
  } else {
    printf("NO ENOUGH MONEY");
  }
}

void Game::constructBuilding(BuildingType type, float x, float y){
  // Trouver la case c pour x;y
  if(this->canBuyBuilding()){
    if (this->canBuildBuildable(type, c)){
      building = new Building(type, c, &this);
      this->setAddVecBuilding(building);
      building->checkTower();
      building->afficher();
    } else {
      printf("NOT BUILDABLE ZONE");
    }
  } else {
    printf("NO ENOUGH MONEY");
  }
}

void Game::gameOver(){

  this->setFinish(true);

  if (this->getWave()<20){
    printf("GAME OVER");
  } else {
      printf("YOU WIN !! ");
  }
    // CLEAN //
    SDL_DestroyWindow(window);
    SDL_Quit();

    for (CatMonster* cat : this->getVecCat()){
        // this->getVecCat().erase(cat);
        cat->destroy();
    }
    for (Tower* tower : this->getVecTower()){
        this->getVecTower().erase(tower);
        tower->destroy();
    }
    for (Building* building : this->getVecBuilding()){
          this->getVecBuilding().erase(building);
          building->destroy();
    }

}
