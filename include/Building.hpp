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
  Case *m_case;
  int m_portee; //jusqu'à quelle case peut tirer
  int m_price; //prix de la tour
  BuildingType type; //type de tour en fonction couleur
  Game *game;

public:
  // Méthodes

  Building(BuildingType type, Case *case, Game *game); //constructeur

  /////GETTERS/////
  Case getCase();
  int getGain();
  int getPortee();
  int getPrice();
  int getBuildingType();
  int getGame();


  /////SETTERS/////
  void setCase(Case* case);
  void setGain(int newGain);
  void setPortee(int portee);
  void setPrice(int price);
  void setBuildingType(BuildingType type);
  void setGame(Game* game);

  //////OTHERS//////


  void afficher();
  void upgradeTower(Tower* t);
  void checkTower();

};

#endif
