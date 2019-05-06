#include <string>
#include "CatMonster.hpp"

using namespace std;

CatMonster {
    
}

//////////GETTERS//////////

int getLife(){
    int m_life = this->m_life;
    return m_life;
}

int getGainDeath(){
    int m_gainDeath = this->m_gainDeath;
    return m_gainDeath;
}

int getSpeed(){
    int m_speed = this->m_speed;
    return m_speed;
}

/////////SETTERS//////////

void setLife(int newLife){
    this->m_life = newLife; //Remplace valeur life par une nouvelle
}

void setGainDeath(int gain){
    //à implémenter
}

void setSpeed(int speed){
    //à implémenter
}

//////////OTHER METHODS//////////

void CatMonster::beDamaged(int nbDamages){
    setLife(this->getLife()-nbDamages); //retire nbdégats reçus à nbPV possédés
    if (!isAlive()){
        this->destroy(); //détruit monstre si n'a plus de vie
    }
}

bool isAlive(){
    return m_life > 0; //renvoie true si m_vie > 0, false sinon
}

void move(){
    //à implémenter    
}

void destroy(){
    //à implémenter
}