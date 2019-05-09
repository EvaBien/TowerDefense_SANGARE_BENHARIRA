#include <string>
#include "Tower.hpp"


using namespace std;

Tower (Type_tower type){
    if (type == RED_LASER){

    } else if (type == GREEN_GRASS) {

    } else if (type == YELLOW_GAMMELLE) {

    } else { // ie BLUE_MILK 

    }
}

//////////GETTERS//////////
int getDamages(){
    int m_damages = this->m_damages;
    return m_damages;
}

int getPortee(){
    int m_portee = this->m_gportee;
    return m_portee;
}

int getCadence(){
    int m_cadence = this->m_cadence;
    return m_cadence;
}

int getPrice(){
    int m_price = this->m_price;
    return m_price;
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

//////////OTHER METHODS//////////

//void Tower::Damaged(int nbDamages){}

bool isBuildable(){
    //à implémenter telle que renvoie true si constructible, false sinon
    //le tout en fonction d'une position déterminée grâce à entité ?
}

//void destroy(){}