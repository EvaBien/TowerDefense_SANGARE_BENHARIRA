#pragma once

#include <vector>
#include <chrono>
#include <thread>
#include <SDL2/SDL.h>

#include "Map.hpp"
#include "CatMonster.hpp"
#include "Tower.hpp"
#include "Building.hpp"


// class CatMonster;
// class Tower;
// class Building;

class Game {
  private:
  // Attributs
  int m_cagnotte;
  int m_nbWave;
  bool m_finished;
  Map* m_map;
  int m_time;

  /*Creation des tableaux d'entités*/
  std::vector<CatMonster*> m_monsters;
  std::vector<Tower*> m_towers;
  std::vector<Building*> m_buildings;


  public:

  Game(std::vector<CatMonster*>& monster, std::vector<Tower*>& towers, std::vector<Building*>& buildings); //constructeur

  //////GETTERS/////
  int getCagnotte();
  int getWave();
  bool getFinish();
  Map* getMap();
  int getTime();
  std::vector<CatMonster*> getVecCat();
  std::vector<Tower*> getVecTower();
  std::vector<Building*> getVecBuilding();

  //////SETTERS/////
  void setCagnotte(int money);
  void setWave(int vague);
  void setFinish(bool value);
  void setMap(Map* map);
  void setTime(int time);
  void setAddVecCat(CatMonster* cat);
  void setAddVecTower(Tower* tower);
  void setAddVecBuilding(Building* building);

  //////OTHERS//////

  void startGame(SDL_Window* window);
  int prepareKitten(int numWave);
  int prepareJustCat(int numWave);
  bool canBuyTower(TowerType type);
  bool canBuyBuilding(BuildingType type);
  void checkBuildings(Tower *t);
  void checkTowers(Building *b);
  void constructTower(TowerType type, float x, float y);
  void constructBuilding(BuildingType type, float x , float y);
  void gameOver();

};
