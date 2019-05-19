#include <string>
#include "../include/Game.hpp"

using namespace std;

Game() {
    this->m_cagnotte = 0;
    this->m_nbWave = 0;
    this->m_finished = false;
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

void Game::setAddVecCat(CatMonster* cat){
  this->m_monsters.push_back(cat);
}
void Game::setAddVecTower(Tower* tower){
  this->m_towers.push_back(tower);
}
void Game::setAddVecBuilding(Building* building){
  this->m_buildings.push_back(building);
}

void Game::setDeleteVecCat(CatMonster* cat){
  this->m_monsters.push_back(cat);
}
void Game::setDeleteVecTower(Tower* tower){
  this->m_towers.push_back(tower);
}
void Game::setDeleteVecBuilding(Building* building){
  this->m_buildings.push_back(building);
}

//////////OTHER METHODS//////////

void Game::startGame(){
  this.setFinish(false);
  int timeWave = 0;
  while (this->getFinish()==false){
      timeWave++;
      if ((loopCount==60*90)){ // SI ca fait 1min30sec
        prepareWave(this->getWave());
        loopCount = 0;
      }
  }
}

void Game::prepareWave(int numWave){
  // faire un pourcentage d'apparition des monstres en fonction du num Wave !
  int nbKitten = 0; // A modifier --> Décroissant en fonction du num Wave
  int nbJustCat = 0; // A modifier --> Croissant " "
  int nbFatCat = 10-(nbKitten+nbJustCat); // Ce qui reste, mais doit être croissant aussi...
// Avec un random ?

  for (int i=1; i<=nbKitten, i++){
    CatMonster* newKitten = new CatMonster(KITTEN);
    this->setAddVecCat(newKitten);
  }
  for (int i=1; i<=nbJustCat, i++){
    CatMonster* newJustCat = new CatMonster(JUSTCAT);
    this->setAddVecCat(newJustCat);
  }
  for (int i=1; i<=nbFatCat, i++){
    CatMonster* newFatCat = new CatMonster(FATCAT);
    this->setAddVecCat(newFatCat);
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
  if (type== ???){
    int price = 100;
  } else if (type==???){
    int price = 100;
  } else if (type==???){
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



void Game::constructTower(TowerType type, Position p){
  if(canBuyTower()){
    // Verifier si on peut construire à cet endroit
    // Si oui construire
    // Verifier si y'a un building autour
    // Si oui appeler fonction upgrade tower
  }
}


void Game::constructTower(BuildingType type, Position p){
  if(canBuyBuilding()){
    // Verifier si on peut construire à cet endroit
    // Si oui construire
    // Verifier si y'a une tour autour
    // Si oui appeler fonction upgrade tower
  }
}

void Game::gameOver(){

  this.setFinish(true);

  if (this->getWave()<20){
    spdlog::critical("GAME OVER");
  } else {
      spdlog::critical("YOU WIN !! ");
  }
    // CLEAN //
    SDL_DestroyWindow(window);
    SDL_Quit();
    for (CatMonster* cat : this->getVecCat()){
      delete cat;
    }
    for (Tower* tower : this->getVecTower()){
      delete tower;
    }
    for (Building* building : this->getVecBuilding()){
      delete building;
    }

}
