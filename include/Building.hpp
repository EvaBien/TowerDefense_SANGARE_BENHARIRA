#ifndef DEF_BUILDING
#define DEF_BUILDING

#include <string>
#include "Entity.hpp"
#include "Tower.hpp"

class Game;

enum BuildingType{
  RADAR,
  WEAPON,
  STOCK,
};

class Building : public Entity {
private:
  // Attributs
  Tile *m_tile;
  int m_portee; //jusqu'à quelle tile peut tirer
  int m_price; //prix de la tour
  BuildingType type; //type de tour en fonction couleur
  Game *game;

public:
  // Méthodes

  Building(BuildingType type, Tile* tile, Game *game); //constructeur

  /////GETTERS/////
  Tile Building::getTile();
  int getGain();
  int getPortee();
  int getPrice();
  BuildingType getType();
  Game* Building::getGame();


  /////SETTERS/////
  void setTile(Tile* tile);
  void setGain(int newGain);
  void setPortee(int portee);
  void setPrice(int price);
  void setBuildingType(BuildingType type);
  void Building::setGame(Game* game);

  //////OTHERS//////


  void afficher();
  void upgradeTower(Tower* t);
  void checkTower();

};

#endif
