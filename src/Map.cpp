#include <string>
#include "../include/CatMonster.hpp"

using namespace std;

Map::Map(){

}
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

void Map::setCaseMap(int position, Case *case){
   this->m_CaseMap[position] = &case;
}

//////////OTHER METHODS//////////

int calculCoordX(int position){
  // y*width+x Accès à la case
}
int calculCoordY(int position){

}

int calculPosition(float x, float y){
 // calcul la position dans el tableau en fonction du clic

 // Exemple  -> Si la position X = 34 et Y <30, sachant qu'une case fait 30, alors on est sur la deuxième case
}

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

    //plutôt tout ranger dans un tableau entre chaque espace

    //puis read tab[2] pour get widthPPM et tab[3] pour get heightPPM
}

void drawMap(){

    //puis for i = 4 à i<taille.tab
    //read tab[i] tab[i+1] tab[i+2] pour obtenir RVB de chaque pixel
    // avec cette info on trace en open-gl un carré de 30 par 30 pixel de la couleur souhaité au bon emplacement
    //comment gérer coordonnées ? ==> avec un compte de carré
    //on sait qu'on veut widthPPM carrés de large et heightPPM carrés de haut ==> permets de réaliser des boucles
}
