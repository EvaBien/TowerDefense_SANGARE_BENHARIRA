#ifndef DEF_GAME
#define DEF_GAME

#include <vector>
#include "Map.hpp"
#include <chrono>
#include <thread>

#include "../include/CatMonster.hpp"
#include "../include/Tower.hpp"
#include "../include/Building.hpp"
#include "../include/Map.hpp"
// class CatMonster;
// class Tower;
// class Building;

class Game{
  private:
  // Attributs
  int m_cagnotte;
  int m_nbWave;
  bool m_finished;
  Map m_map;
  int m_time;

  /*Creation des tableaux d'entités*/
  std::vector<CatMonster*> m_monsters;
  std::vector<Tower*> m_towers;
  std::vector<Building*> m_buildings;


  public:

  Game(); //constructeur

  //////GETTERS/////
  int getCagnotte();
  int getWave();
  bool getFinish();
  Map getMap();
  int getTime();
  std::vector<CatMonster*> getVecCat();
  std::vector<Tower*> getVecTower();
  std::vector<Building*> getVecBuilding();

  //////SETTERS/////
  void setCagnotte(int money);
  void setWave(int vague);
  void setFinish(bool value);
  void setMap(Map map);
  void setTime(int time);
  void setAddVecCat(CatMonster* cat);
  void setAddVecTower(Tower* tower);
  void setAddVecBuilding(Building* building);
  // void setDeleteVecCat(CatMonster* cat);
  // void setDeleteVecTower(Tower* tower);
  // void setDeleteVecBuilding(Building* building);

  //////OTHERS//////

  void startGame();
  void prepareWave(int numWave);
  bool canBuyTower(TowerType type);
  bool canBuyBuilding(BuildingType type);
  bool canBuildTower(TowerType type, Tile *t);
  bool canBuildBuilding(BuildingType type, Tile *t);
  void checkBuildings(Tower *t);
  void checkTowers(Building *b);
  void constructTower(TowerType type, float x, float y);
  void constructBuilding(BuildingType type, float x , float y);
  void gameOver();

};

#endif
