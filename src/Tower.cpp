#include <string>
#include "../include/Tower.hpp"


using namespace std;

Tower (TowerType type){ //on considère 100 comme valeur neutre
    if (type == RED_LASER){
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
int getDamages(){
    return this->m_damages;
}

int getPortee(){
    return this->m_gportee;
}

int getCadence(){
    return this->m_cadence;
}

int getPrice(){
    return this->m_price;
}

TowerType getTowerType(){
    return this->type;
}

CatMonster getTarget(){
  return this->target;
}

/////////SETTERS//////////
void setDamages(int damages){
    this->m_damages =  damages; //Remplace valeur damages par une nouvelle
}

void setPortee(int portee){
    this->m_portee =  portee;
}

void setCadence(int cadence){
    this->m_cadence =  cadence;
}

void setPrice(int price){
    this->m_price =  price;
}

void setTowerType(towerType){
    this->type = towerType;
}

void setTarget(CatMonster &target){
    this->target=target;
}

//////////OTHER METHODS//////////

void afficher(){

}

void attack(){

    // Cherche target
    // Si this->target !=NULL
        // Shoot monster
            // Si touché gagne argent
      // Cherche nouvelle target si morte ou plus dans porté

    this->target.beDamaged(this.getDamages());
}

bool isBuildable(){
    //à implémenter telle que renvoie true si constructible, false sinon
    //le tout en fonction d'une position déterminée grâce à entité ?
}
