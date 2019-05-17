#include <string>
#include "../include/CatMonster.hpp"

using namespace std;

CatMonster(CatMonsterType type) {
    if (type == KITTEN){
        m_life = 60;
        m_speed = 150;
        m_gainDeath = 2;
    } else if (type == FATCAT) {
        m_life = 140;
        m_speed = 60;
        m_gainDeath = 10;
    } else {
        m_life = 100;
        m_speed = 100;
        m_gainDeath =5 ;
    }
}

//////////GETTERS//////////

int getLife(){
    return this->m_life;
}

int getGainDeath(){
    return this->m_gainDeath;
}

int getSpeed(){
    return this->m_speed;
}

int getType(){
  return this->type;
}

/////////SETTERS//////////

void setLife(int newLife){
    this->m_life = newLife; //Remplace valeur life par une nouvelle
}

void setGainDeath(int gain){
    this->m_gainDeath=gain;
}

void setSpeed(int speed){
    this->m_speed=speed;
}

//////////OTHER METHODS//////////

void CatMonster::beDamaged(int nbDamages){
    setLife(this->getLife()-nbDamages); //retire nbdégats reçus à nbPV possédés
    if (!this->isAlive()){
        this->destroy(); //détruit monstre si n'a plus de vie
    }
}

bool isAlive(){
    return this->m_life > 0; //renvoie true si m_vie > 0, false sinon
}

void move(){
    while (this->isAlive()){
      setX(/**/);
      setY(/**/);
    }
}

void destroy(){
    // Récupérer le gain pour la cagnotte
    // Retirer de la liste de vecteurs
    // Se retirer de la tour qui ciblait
}
