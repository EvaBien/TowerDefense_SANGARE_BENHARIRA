#ifndef DEF_CATMONSTER
#define DEF_CATMONSTER

#include <string>
#include "Entity.hpp"
#include "Map.hpp"

class Game;
class Tower;

enum CatMonsterType{
  KITTEN,
  FATCAT,
  JUSTCAT,
};


class CatMonster : public Entity{
private:
  // Attributs
  int m_life; //nb point de vie
  int m_gainDeath; //nb piece reçu par joueur qd monstre meurt
  int m_speed; //vitesse à laquelle monstre se déplace
  CatMonsterType type; //type de chat mutant
  Game *game;

public:

  CatMonster(CatMonsterType type, Game *game, Case* case); //constructeur
  ~CatMonster(); // Desctructeur

  //////GETTERS/////
  int getLife();
  int getGainDeath();
  int getSpeed();
  int getType();
  Game getGame();

  //////SETTERS/////
  void setLife(int newLife);
  void setGainDeath(int gain);
  void setSpeed(int speed);


  //////OTHERS//////

  void afficher();
  void beDamaged(int nbDamages, Tower *tower);
  bool isAlive();
  Case chooseDestination(Map *m);
  void move(Map *m);
  void destroy(Tower *t);
  // int Dijsktra(int current, int destination);

};

#endif
