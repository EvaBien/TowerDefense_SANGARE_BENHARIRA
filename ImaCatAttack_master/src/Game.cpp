#include "Game.hpp"

#include <string>

#include "Tile.hpp"

/* Nombre minimal de millisecondes separant le rendu de deux images */
static const int FRAMERATE_MILLISECONDS = 1000 / 60;
using namespace std;

Game::Game(std::vector<CatMonster*>& monster, std::vector<Tower*>& towers, std::vector<Building*>& buildings){ //constructeur
  this->m_cagnotte = 100;
  this->m_nbWave = 0;
  this->m_finished = false;
  this->m_map;
  this->m_time=0;
  // Initialiser 3 vecteurs

  this->m_monsters = monster;
  this->m_towers = towers;
  this->m_buildings =  buildings;
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

Map* Game::getMap(){
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

void Game::setMap(Map *map){
  this->m_map=map;
}

void Game::setTime(int time){
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

//////////OTHER METHODS//////////

void Game::startGame(SDL_Window* window){
	/*
	Tile* entry;
	Tile* out;
	*/
	Map* myMap = new Map();

  myMap->initMap();
  this->setMap(myMap);

  Node* list = myMap->getListNodes();
  //entry = list[0].getTile();
  //out = list[1].getTile();

  this->setFinish(false);
  this->setTime(0);
  int nbWave = 0;

  /* GAME LOOP */

  while (this->getFinish()==false){


	/* Echange du front et du back buffer : mise a jour de la fenetre */
	SDL_GL_SwapWindow(window);

    this->setWave(nbWave++);
    if ((this->getTime()%(60*90)==0)){ // SI ca fait 1min30sec // OU UTILISER std::this_thread::sleep_for(std::chrono::milliseconds(60*90));
      prepareWave(this->getWave());
      this->setTime(0);

      if(this->getWave()>=20){
        this->gameOver();
      }
    }
    this->setTime(this->getTime()+1);
  }
}

void Game::prepareWave(int numWave){
  // faire un pourcentage d'apparition des monstres en fonction du num Wave !
  int nbKitten = 2; // A modifier --> Décroissant en fonction du num Wave
  int nbJustCat = 6; // A modifier --> Croissant " "
  int nbFatCat = 10-(nbKitten+nbJustCat); // Ce qui reste, mais doit être croissant aussi...
  // Avec un random ?
  /*
  for (int i=0; i<nbKitten; i++){
    CatMonster* newKitten = new CatMonster(KITTEN,this, entry);
    this->setAddVecCat(newKitten);
    newKitten->afficher();
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
  }
  for (int i=0; i<nbJustCat; i++){
    CatMonster* newJustCat = new CatMonster(JUSTCAT,this, entry);
    this->setAddVecCat(newJustCat);
    newJustCat->afficher();
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
  }
  for (int i=0; i<nbFatCat; i++){
    CatMonster* newFatCat = new CatMonster(FATCAT,this, entry);
    this->setAddVecCat(newFatCat);
    newFatCat->afficher();
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
  }
  */
}

bool Game::canBuyTower(TowerType type){
  int price;
  if (type== RED_LASER){
    int price = 100;
  } else if (type==GREEN_GRASS){
    int price = 100;
  } else if (type==YELLOW_GAMMELLE){
    int price = 100;
  } else {
    int price = 100;
  }
  if (this->getCagnotte()-price >=0){
    this->setCagnotte(this->getCagnotte()-price);
    return true;
  }
  return false;
}

bool Game::canBuyBuilding(BuildingType type){
  int price; // A modifier avec les noms des type de building
  if (type== RADAR){
    int price = 100;
  } else if (type==WEAPON){
    int price = 100;
  } else {
    int price = 100;
  }
  if (this->getCagnotte()-price >=0){
    this->setCagnotte(this->getCagnotte()-price);
    return true;
  }
  return false;
}

void Game::checkTowers(Building *b){
  int portee = b->getPortee();

  for (Tower* tower : this->getVecTower()){
    Tile *tTile = tower->getTile();
    float distance = tTile->distance(b->getTile());
    if (distance <= portee){
      b->upgradeTower(tower);
    }
  }
}

void Game::checkBuildings(Tower *t){

  for (Building* building : this->getVecBuilding()){
    int portee = building->getPortee();
    Tile *bTile = building->getTile();
    float distance = bTile->distance(t->getTile());
    if (distance <= portee){
      building->upgradeTower(t);
    }
  }
}

void Game::constructTower(TowerType type, float x, float y){
  Map* map = this->getMap();
  int position = map->calculPosition(x,y);
  Tile* t = map->getTile(position);
  if(this->canBuyTower(type)){
    if (t->getBuildable()){
      Tower* tower = new Tower(type, t, this);
      this->setAddVecTower(tower);
      this->checkBuildings(tower);
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
  Map* map = this->getMap();
  int position = map->calculPosition(x,y);
  Tile* t = map->getTile(position);
  if(this->canBuyBuilding(type)){
    if (t->getBuildable()){
      Building* building = new Building(type, t, this);
      this->setAddVecBuilding(building);
      this->checkTowers(building);
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
    printf("YOU WON !! ");
  }

  std::vector<CatMonster *> catVec = this->getVecCat();
  catVec.erase(catVec.begin(), catVec.end());

  std::vector<Tower *>towerVec = this->getVecTower();
  towerVec.erase(towerVec.begin(), towerVec.end());

  std::vector<Building *> buildVec = this->getVecBuilding();
  buildVec.erase(buildVec.begin(), buildVec.end());


  // CLEAN //
  SDL_Quit();

}
