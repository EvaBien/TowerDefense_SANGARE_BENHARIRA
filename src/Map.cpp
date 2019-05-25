#include <string>
#include "../include/CatMonster.hpp"

using namespace std;


Map::~Map(){};

//////////GETTERS//////////

int Map::getHeight(){
    return this->m_height;
}

int Map::getWidth(){
    return this->m_width;
}

/////////SETTERS//////////

void Map::setHeight(int newHeight){
    this->m_height = newHeight; //Remplace valeur Height par une nouvelle
}

void Map::setWidth(int newWidth){
    this->m_width=newWidth; //Remplace valeur Width par une nouvelle
}

//////////OTHER METHODS//////////

void Map::Scale(int heightPPM, int widthPPM){
    if (HeightPPM!=0 && widthPPM!=0){
        setheight(this->heightPPM*30); //donne hauteur de notre image de ref fois 30 
        setWidth(this->widthPPM*30); //donne largeur de notre image de ref fois 30 
    } else {
        printf("The picture does not have a proper size")
    }
}

void readPPM(){
    //lire le fichier ppm
    //ignorer ligne 1
    // récupérer largeur et hauteur sur ligne 2
    //ignorer ligne 3
    //commencer à parcourir et rentrer valeur dans tableau à partir de ligne 4
}