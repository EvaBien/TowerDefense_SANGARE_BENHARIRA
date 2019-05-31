#ifndef DEF_GAME
#define DEF_GAME

#include<vector>
#include "Map.hpp"

class CatMonster;
class Tower;
class Building;

class Game{
private:
  // Attributs
  int m_cagnotte;
  int m_nbWave;
  bool m_finished;
  Map m_map;
  int m_time;

  /*Creation des tableaux d'entités*/
  vector<CatMonster*> m_monsters;
  vector<Tower*> m_towers;
  vector<Building*> m_buildings;


public:

  Game(); //constructeur

  //////GETTERS/////
  int getCagnotte();
  int getWave();
  bool getFinish();
  Map getMap();
  int getTime();
  vector<CatMonster*> getVecCat();
  vector<Tower*> getVecTower();
  vector<Building*> getVecBuilding();

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
  bool canBuildTower(TowerType type, Tile c);
  bool canBuildBuilding(BuildingType type, Tile c);
  void checkBuildings(Tower t);
  void checkTowers(Building b);
  void construcTower(TowerType type, Tile *c);
  void construcBuilding(BuildingType type, Tile *c);
  void gameOver();

};

#endif
