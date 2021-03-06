#include "CatMonster.hpp"

#include <string>
#include <vector>
#include <glad/glad.h>

#include "Game.hpp"
#include "TextureController.hpp"
#include "Tower.hpp"
#include "Node.hpp"

CatMonster::CatMonster(CatMonsterType type, Game *game, Tile *tile) {
  if (this->type == KITTEN){
    this->m_life = 60;
    this->m_speed = 150;
    this->m_gainDeath = 2;
    this->m_affichage = "images/kitten.png";
  } else if (this->type == FATCAT) {
    this->m_life = 140;
    this->m_speed = 60;
    this->m_gainDeath = 10;
    this->m_affichage = "images/fatcat.png";
  } else {
    this->m_life = 100;
    this->m_speed = 100;
    this->m_gainDeath =5;
    this->m_affichage = "images/justcat.png";
  }
  this->m_tile= tile;
  this->game=game;
  this->m_x = tile->getX();
  this->m_y=tile->getY();// Position de l'entrée de la map
  // Faire un random si plusieurs entrées
}

CatMonster::~CatMonster(){0;};

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

Game* CatMonster::getGame(){
  return this->game;
}

GLuint CatMonster::getTexture(){
  return this->m_texture;
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

void CatMonster::setTexture(GLuint texture){
  this->m_texture = texture;
}

//////////OTHER METHODS//////////

void CatMonster::drawCat(GLuint texture, float x, float y){
  glPushMatrix();
  glTranslatef(x,y,0);
  drawPicture(texture, 50, 50); // Taille tower
  glPopMatrix();
}

void CatMonster::afficher(){
  GLuint catTexture = 0;
  std::string pathCat = this->getAffichage();
  catTexture=loadTexture(pathCat.c_str());
  this->setTexture(catTexture);

  glPushMatrix();
  glTranslatef(this->getTile()->getX(),this->getTile()->getY(),0);
  drawPicture(catTexture, 50, 50); // Taille tower
  glPopMatrix();
}



void CatMonster::beDamaged(int nbDamages, Tower* tower){
  setLife(this->getLife()-nbDamages); //retire nbdégats reçus à nbPV possédés
  if (!this->isAlive()){
    this->destroy(tower); //détruit monstre si n'a plus de vie
  }
}

bool CatMonster::isAlive(){
  return this->m_life > 0;
}

Tile* CatMonster::chooseDestination(Map *m) {
	/*
  // Retourne la Tile suivante dans le graph
  Tile *current = this->getTile();
  Node* list = m->getListNodes();
  int i=0;
  while (list[i].getNext()!=nullptr){
    if (list[i].getTile() == current){
      int successor = list[i].getSuccessor();
      Node next = list[successor];
      // Pour utilisation de Dijsktra -> Node next = dijsktra(list[i]);
      return next.getTile();
    }
    i++;
  }
  */
  return nullptr;
}

void CatMonster::move(Map *m){
  while (this->isAlive()){
    Tile *current = this->getTile();
    if (current->getType()==EXIT){
      Game *game = this->getGame();
      game->gameOver();
      exit(0);
    } else {
      if (current->getType()==NODE || current->getType()==ENTRY){
        Tile *destination = this->chooseDestination(m);
        while (current != destination){

          ////////// BRASSENHAM ///////////
          float initialX = current->getX();
          float initialY = current->getY();
          float destinX = destination->getX();
          float destinY= destination->getY();
          float errorX=0.0;
          float errorY=0.0;
          int deltaX = (int)(destinX - initialX);
          int deltaY = (int)(destinY - initialY);
          int deltaX1 = fabs(deltaX);
          int deltaY1 = fabs(deltaY);
          int pX = 2*deltaY1-deltaX1;
          int pY = 2*deltaX1-deltaY1;
          int x;
          int y;
          if (deltaY1<=deltaX1){
            if(deltaX>=0){
              x=initialX;
              y=initialY;
              errorX=destinX;
            } else {
              x=destinX;
              y=destinY;
              errorX=initialX;
            }
            this->setX(x);
            this->setY(y);
            this->drawCat(this->getTexture(),x,y);
            for (int i=0; x<errorX;i++){
              if(pX<0){
                pX=pX+2*deltaY1;
              } else {
                if((deltaX<0 && deltaY<0) || (deltaX>0 && deltaY>0)){
                  y=y+1;
                } else {
                  y=y-1;
                }
                pX=pX+2*(deltaY1-deltaX1);
              }
              this->setX(x);
              this->setY(y);
              this->drawCat(this->getTexture(),x,y);
            }
          } else {
            if(deltaY>=0) {
              x=initialX;
              y=initialY;
              errorY=destinY;
            } else {
              x=destinX;
              y=destinY;
              errorY=initialY;
            }
            this->setX(x);
            this->setY(y);
            this->drawCat(this->getTexture(),x,y);
            for(int i=0;y<errorY;i++){
              y=y+1;
              if(pY<=0){
                pY=pY+2*deltaX1;
              }
              else{
                if((deltaX<0 && deltaY<0) || (deltaX>0 && deltaY>0)){
                  x=x+1;
                } else {
                  x=x-1;
                }
                pY=pY+2*(deltaX1-deltaY1);
              }
              this->setX(x);
              this->setY(y);
              this->drawCat(this->getTexture(),x,y);
            }
          }
        }
      }
    }
  }
}

void CatMonster::destroy(Tower *t){
  Game *game = this->getGame();
  int money = game->getCagnotte();
  game->setCagnotte(money+this->getGainDeath());
  printf("Montre mort ! La nouvelle cagnotte : %d", game->getCagnotte());
  std::vector<CatMonster *> vector = game->getVecCat();
  int i=0;
  for (i; i<vector.size(); i++){
    if (vector[i] == this){
      vector.erase(vector.begin()+i);
    }
  }
    t->setTarget(nullptr);
}
