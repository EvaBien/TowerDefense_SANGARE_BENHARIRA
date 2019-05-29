#include <string>
#include "../include/Tower.hpp"


using namespace std;

Tower::Tower (TowerType type, Case &case){ //on considère 100 comme valeur neutre
    if (this->type == RED_LASER){
        this->m_damages = 150; //bcp de dégâts
        this->m_portee = 100;
        this->m_cadence = 50; //cadence faible
        this->m_price = 100;
        this->m_affichage = "../images/towerRed.png";
    } else if (this->type == GREEN_GRASS) {
        this->m_damages = 100; // dégâts moyens
        this->m_portee = 50; //faible portée
        this->m_cadence = 150; //tirent très rapidement
        this->m_price = 100;
        this->m_affichage = "../images/towerGreen.png";

    } else if (type == YELLOW_GAMMELLE) { //tirents sur tous les ennemis à leur portée
        this->m_damages = 50; //peu de dégâts
        this->m_portee = 50; //portée très limitée
        this->m_cadence = 125; //bonne cadence de tir
        this->m_price = 100;
        this->m_affichage = "../images/towerYellow.png";

    } else { // ie BLUE_MILK
      this->m_damages = 50; //peu de dégâts
      this->m_portee =150 ; //bonne portée
      this->m_cadence = 150; //bonne cadence de tir
      this->m_price = 100;
      this->m_affichage = "../images/towerBlue.png";
    }
    this->m_case=&case;
    this->m_x = case->getX(); // Position de l'entrée de la map
    this->m_y = case->getY(); // Position de l'entrée de la map
}

//////////GETTERS//////////

Case Tower::getCase(){
  return this->m_case;
}

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

Game Tower::getGame(){
  return this->game;
}
/////////SETTERS//////////

void Tower::setCase(Case *case){
  this->m_case=case;
  this->setX(case->getX());
  this->setY(case->getY());
}

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

void Tower::setTowerType(towerType type){
    this->type = type;
}

void Tower::setTarget(CatMonster *target){
    this->target=target;
}

void Tower::setGame(Game *game){
  this->game=game;
}

//////////OTHER METHODS//////////

void Tower::afficher(){
    GLuint towerTexture = 0;
    string pathTower = this->getAffichage();
    towerTexture=loadTexture(pathTower);

    glPushMatrix();
    glTranslate(this->getPosition()->getX(),this->getPosition()->getY(),0);
    drawPicture(towerTexture, 20, 20); // Taille tower
    glPopMatrix();
}

void Tower::attack(){

    // Cherche target
    // Si this->target !=NULL
        // Shoot monster
            // Si touché gagne argent
      // Cherche nouvelle target si morte ou plus dans porté

    this->target.beDamaged(this.getDamages(), &this);
}
