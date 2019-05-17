#include <string>
#include "Game.hpp"

using namespace std;

Game() {
    m_cagnotte = 0;
    m_nbVague = 0;
    m_finished = false;
    // Initialiser 3 vecteurs
}

//////////GETTERS//////////

int getCagnotte(){
    return this->m_cagnotte;
}

int getVague(){
    return this->m_nbVague;
}

int getFinish(){
    return this->m_finished;
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

int setFinish(){
    this->m_finished = !this->m_finished;
}

// void setVecCat(){
// }
//
// void setVecTower(){
// }
//
// void setVecBuilding(){
// }

//////////OTHER METHODS//////////

void startGame(){
  this.setFinish();
}

void lancerVague(int numVague){
  // faire un pourcentage d'apparition des monstres en fonction du num Vague !
  int nbKitten = 0; // A modifier --> Décroissant en fonction du num Vague
  int nbJustCat = 0; // A modifier --> Croissant " "
  int nbFatCat = 10-(nbKitten+nbJustCat); // Ce qui reste, mais doit être croissant aussi...
// Avec un random ?

}

bool canBuyTower(TowerType type){
  if (type== RED_LASER){
    int price = 100;
  } else if (type==GREEN_GRASS){
    int price = 100;
  } else if (type==YELLOW_GAMMELLE){
    int price = 100;
  } else {
    int price = 100;
  }
    if (this->m_cagnotte-price >=0){
      this.setCagnotte(this->m_cagnotte-price);
      return true;
    }
    return false;
}

bool canBuyBuilding(BuildingType type){ // A modifier avec les noms des type de building
  if (type== ???){
    int price = 100;
  } else if (type==???){
    int price = 100;
  } else if (type==???){
    int price = 100;
  } else {
    int price = 100;
  }
    if (this->m_cagnotte-price >=0){
      this.setCagnotte(this->m_cagnotte-price);
      return true;
    }
    return false;
}
    // Récupérer le gain pour la cagnotte
    // Retirer de la liste de vecteurs
void gameOver(){
    // Destroy toutes les entités
    // Fin de partie
    this.setFinish();
}
