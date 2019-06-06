#pragma once

#include <string>

#include "Entity.hpp"
#include "CatMonster.hpp"

class Game; // Forward declaration

enum TowerType{
  RED_LASER,
  GREEN_GRASS,
  YELLOW_GAMMELLE,
  BLUE_MILK,
};

class Tower : public Entity {
private:
  // Attributs
  Tile *m_tile;
  int m_damages; //nb point de dégat
  int m_portee; //jusqu'à quelle tile peut tirer
  int m_cadence; //vitesse à laquelle tour peut tirer
  int m_price; //prix de la tour
  TowerType type; //type de tour en fonction couleur
  CatMonster *target;
  Game *game;

public:
  // Méthodes

  Tower(TowerType type, Tile* tile, Game *game); //constructeur

  /////GETTERS/////
  Tile* getTile();
  int getDamages();
  int getPortee();
  int getCadence();
  int getPrice();
  TowerType getTowerType();
  Game* getGame();
  CatMonster* getTarget();


  /////SETTERS/////
  void setTile(Tile *tile);
  void setDamages(int newDamages);
  void setPortee(int portee);
  void setCadence(int cadence);
  void setPrice(int price);
  void setTowerType(TowerType type);
  void setGame(Game *game);
  void setTarget(CatMonster *target);


  //////OTHERS//////

  void afficher();
  void attack();
  void searchTarget();

};
