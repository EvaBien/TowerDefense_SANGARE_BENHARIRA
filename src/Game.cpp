#include <string>
#include "Game.hpp"

using namespace std;

Game() {
    m_cagnotte = 0;
    m_nbVague = 0;
    // Initialiser 3 vecteurs
}

//////////GETTERS//////////

int getCagnotte(){
    return this->m_cagnotte;
}

int getVague(){
    return this->m_nbVague;
}

// ?? getVecCat(){
// }
// 
// ?? getVecTower(){
// }
//
// ?? getVecBuilding(){
// }

/////////SETTERS//////////


void SetCagnotte(int money){
  this->m_cagnotte=money;
}

void SetVague(int nbVague){
    this->m_nbVague=nbVague;
}

void setVecCat(){
}

void setVecTower(){
}

void setVecBuilding(){
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
}
