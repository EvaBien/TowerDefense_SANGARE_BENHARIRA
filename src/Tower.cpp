#include <string>
#include "../include/Tower.hpp"


using namespace std;

Tower::Tower (TowerType type){ //on considère 100 comme valeur neutre
    if (this->type == RED_LASER){
        m_damages = 150; //bcp de dégâts
        m_portee = 100;
        m_cadence = 50; //cadence faible
        m_price = 100;
    } else if (type == GREEN_GRASS) {
        m_damages = 100; // dégâts moyens
        m_portee = 50; //faible portée
        m_cadence = 150; //tirent très rapidement
        m_price = 100;
    } else if (type == YELLOW_GAMMELLE) { //tirents sur tous les ennemis à leur portée
        m_damages = 50; //peu de dégâts
        m_portee = 50; //portée très limitée
        m_cadence = 125; //bonne cadence de tir
        m_price = 100;
    } else { // ie BLUE_MILK
        m_damages = 50; //peu de dégâts
        m_portee =150 ; //bonne portée
        m_cadence = 150; //bonne cadence de tir
        m_price = 100;
    }
}

//////////GETTERS//////////
int Tower::getDamages(){
    return this->m_damages;
}

int Tower::getPortee(){
    return this->m_gportee;
}

int Tower::getCadence(){
    return this->m_cadence;
}

int Tower::getPrice(){
    return this->m_price;
}

TowerType Tower::getTowerType(){
    return this->type;
}

CatMonster Tower::getTarget(){
  return this->target;
}

/////////SETTERS//////////
void Tower::setDamages(int damages){
    this->m_damages =  damages; //Remplace valeur damages par une nouvelle
}

void Tower::setPortee(int portee){
    this->m_portee =  portee;
}

void Tower::setCadence(int cadence){
    this->m_cadence =  cadence;
}

void Tower::setPrice(int price){
    this->m_price =  price;
}

void Tower::setTowerType(towerType){
    this->type = towerType;
}

void Tower::setTarget(CatMonster &target){
    this->target=target;
}

//////////OTHER METHODS//////////

void Tower::afficher(){

}

void Tower::attack(){

    // Cherche target
    // Si this->target !=NULL
        // Shoot monster
            // Si touché gagne argent
      // Cherche nouvelle target si morte ou plus dans porté

    this->target.beDamaged(this.getDamages());
}

bool Tower::isBuildable(Position p){
    //à implémenter telle que renvoie true si constructible, false sinon
    //le tout en fonction d'une position déterminée grâce à entité ?
}
