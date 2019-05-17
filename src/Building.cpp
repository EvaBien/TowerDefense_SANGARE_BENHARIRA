#include <string>
#include "../include/Building.hpp"


using namespace std;

Building (BuildingType type){ // A COMPLETER NE FONCTION DU SUJET
    if (type == ???){
        m_gain = ; //bcp de dégâts
    } else if ((type == ???){
        m_gain = ; //bcp de dégâts
    } else if (type == ???){
        m_gain = ; //bcp de dégâts
    } else { // ie BLUE_MILK
        m_gain = ; //bcp de dégâts
    }
}

//////////GETTERS//////////
int getGain(){
    return this->m_gain;
}

int getPortee(){
    return this->m_gportee;
}


int getPrice(){
    return this->m_price;
}

TowerType getBuildingType(){
    return this->type;
}


/////////SETTERS//////////

void setGain(int gain){
  this->m_gain = gain;
}

void setPortee(int portee){
    this->m_portee =  portee;
}


void setPrice(int price){
    this->m_price =  price;
}

void setBuildingType(towerType){
    this->type = towerType;
}


//////////OTHER METHODS//////////

void afficher(){

}

bool isBuildable(){
    //à implémenter telle que renvoie true si constructible, false sinon
    //le tout en fonction d'une position déterminée grâce à entité ?
}

void upgradeTower(){
  // Parcourir vecteur des tours, if distance < à jsp quoi, upgrade en fonction du type
}
