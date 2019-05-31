#include <string>
#include "../include/CatMonster.hpp"

using namespace std;

CatMonster::CatMonster(CatMonsterType type, Game *game, Case *c) {
    if (this->type == KITTEN){
        this->m_life = 60;
        this->m_speed = 150;
        this->m_gainDeath = 2;
        this->m_affichage = "../images/kitten.png";
    } else if (this->type == FATCAT) {
        this->m_life = 140;
        this->m_speed = 60;
        this->m_gainDeath = 10;
        this->m_affichage = "../images/fatcat.png";
    } else {
        this->m_life = 100;
        this->m_speed = 100;
        this->m_gainDeath =5;
        this->m_affichage = "../images/justcat.png";
      }
      this->m_position= new Position(0,0);
      this->game=game; // Position de l'entrée de la map
    // Faire un random si plusieurs entrées
}

CatMonster::~CatMonster(){};

//////////GETTERS//////////

int CatMonster::getLife(){
    return this->m_life;
}

int CatMonster::getGainDeath(){
    return this->m_gainDeath;
}

int CatMonster::getSpeed(){
    return this->m_speed;
}

int CatMonster::getType(){
  return this->type;
}

Game CatMonster::getGame(){
  return this->game;
}
/////////SETTERS//////////

void CatMonster::setLife(int newLife){
    this->m_life = newLife; //Remplace valeur life par une nouvelle
}

void CatMonster::setGainDeath(int gain){
    this->m_gainDeath=gain;
}

void CatMonster::setSpeed(int speed){
    this->m_speed=speed;
}

void CatMonster::setGame(Game *game){
  this->game=game;
}
//////////OTHER METHODS//////////

void CatMonster::afficher(){
    GLuint catTexture = 0;
    string pathCat = this->getAffichage();
  catTexture=loadTexture(pathCat);

    glPushMatrix();
    glTranslate(this->getPosition()->getX(),this->getPosition()->getY(),0);
    drawPicture(catTexture, 10, 10); // Taille tower
    glPopMatrix();
}



void CatMonster::beDamaged(int nbDamages, Tower* tower){
    setLife(this->getLife()-nbDamages); //retire nbdégats reçus à nbPV possédés
    if (!this->isAlive()){
        this->destroy(tower); //détruit monstre si n'a plus de vie
    }
}

bool CatMonster::isAlive(){
    return this->m_life > 0; //renvoie true si m_vie > 0, false sinon
}

Case CatMonster::chooseDestination(){
 // Retourne la Case suivante dans le graph

 // Je récup la case de mon monstre actuellement
 // Je cherche dans ma liste de node de la map où je suis
 // Je cherche mon next // Apppel Dijsktra
 // Je retourne la case de mon next;
}

void CatMonster::move(Map *m){
    while (this->isAlive()){
      Case current = this->getCase();
      if (current->getType()==OUT){
        this->getGame()->gameOver();
        exit();
      } else {
        if (current->getType()==NODE || current->getType()==IN){

        }
      // Je cherche la position de la Case actuelle
      // Si c'est un coude ou une intersection --> choose Destination Case;
      // J'ai une nouvelle destination
      // Tant que je ne suis pas arrivée à destination
      // Le monstre avance grace à Brassenham
    }
}

void CatMonster::destroy(Tower *t){
  Game* game = this->getGame();
  int money = game->getCagnotte();
  game->setCagnotte(money+this->getGainDeath());
  std::vector<CatMonster*> vector = game->getVecCat();
  int i=0;
  for (i; i<vector.size(); i++){
    if (vector[i] == this){
      vector.erase(vector.begin()+i);
    }
  }
  if (this=== t->getTarget()){
    t->setTarget(nullptr);
  }

    // Retirer de la liste de vecteurs
    // Se retirer de la tour qui ciblait
    //ajout pointeur vers game ==> cf constructeur à modif aussi &this dans game à appel constructeur
}
