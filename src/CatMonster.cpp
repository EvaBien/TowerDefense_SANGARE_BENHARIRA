#include <string>
#include "../include/CatMonster.hpp"

using namespace std;

CatMonster::CatMonster(CatMonsterType type) {
    if (this->type == KITTEN){
        m_life = 60;
        m_speed = 150;
        m_gainDeath = 2;
    } else if (this->type == FATCAT) {
        m_life = 140;
        m_speed = 60;
        m_gainDeath = 10;
    } else {
        m_life = 100;
        m_speed = 100;
        m_gainDeath =5 ;
    }
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

//////////OTHER METHODS//////////

void CatMonster::beDamaged(int nbDamages){
    setLife(this->getLife()-nbDamages); //retire nbdégats reçus à nbPV possédés
    if (!this->isAlive()){
        this->destroy(); //détruit monstre si n'a plus de vie
    }
}

bool CatMonster::isAlive(){
    return this->m_life > 0; //renvoie true si m_vie > 0, false sinon
}

void CatMonster::move(){
    while (this->isAlive()){
      float newX = ; //??
      float newY = ; //??
      this->Position.setPosition(newX, newY); // Completer avec nouveau calcul
    }
}

void CatMonster::destroy(){
    // Récupérer le gain pour la cagnotte
    // Retirer de la liste de vecteurs
    // Se retirer de la tour qui ciblait
}
