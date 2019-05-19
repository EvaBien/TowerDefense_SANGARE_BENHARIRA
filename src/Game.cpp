#include <string>
#include "../include/Game.hpp"

using namespace std;

Game() {
    m_cagnotte = 0;
    m_nbVague = 0;
    m_finished = false;
    // Initialiser 3 vecteurs
}

//////////GETTERS//////////

int Game::getCagnotte(){
    return this->m_cagnotte;
}

int Game::getVague(){
    return this->m_nbVague;
}

int Game::getFinish(){
    return this->m_finished;
}

// ?? Game::getVecCat(){
// }
//
// ??Game:: getVecTower(){
// }
//
// ??Game:: getVecBuilding(){
// }

/////////SETTERS//////////


void Game::setCagnotte(int money){
  this->m_cagnotte=money;
}

void Game::setVague(int nbVague){
    this->m_nbVague=nbVague;
}

int Game::setFinish(){
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

void Game::startGame(){
  this.setFinish();
}

void Game::lancerVague(int numVague){
  // faire un pourcentage d'apparition des monstres en fonction du num Vague !
  int nbKitten = 0; // A modifier --> Décroissant en fonction du num Vague
  int nbJustCat = 0; // A modifier --> Croissant " "
  int nbFatCat = 10-(nbKitten+nbJustCat); // Ce qui reste, mais doit être croissant aussi...
// Avec un random ?

}

bool Game::canBuyTower(TowerType type){
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

bool Game::canBuyBuilding(BuildingType type){ // A modifier avec les noms des type de building
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


void Game::constructTower(TowerType type, Position p){
  if(canBuyTower()){
    // Verifier si on peut construire à cet endroit
    // Si oui construire
    // Verifier si y'a un building autour
    // Si oui appeler fonction upgrade tower
  }
}


void Game::constructTower(BuildingType type, Position p){
  if(canBuyBuilding()){
    // Verifier si on peut construire à cet endroit
    // Si oui construire
    // Verifier si y'a une tour autour
    // Si oui appeler fonction upgrade tower
  }
}

void Game::gameOver(){
    // Destroy toutes les entités
    // Fin de partie
    this.setFinish();
}
