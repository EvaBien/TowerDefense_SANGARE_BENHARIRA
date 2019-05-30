#include <string>
#include "../include/Map.hpp"

using namespace std;

Map::Map(){}

Map::~Map(){};

//////////GETTERS//////////

int Map::getHeight(){
    return this->m_height;
}

int Map::getWidth(){
    return this->m_width;
}

Case Map::getCase(int position){
  return this->mCaseMap[position];
}
Case* Map::getAllCases(){
  return this->m_CaseMap;
}

int Map::getSizeCases(){
  return this->getHeight()*this->getWidth();
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

void Map::setAllCases(Case *tab){
  this->m_CaseMap=tab;
}

void Map::setParams(int height, int width){
  this->m_height=height;
  this->m_width=width;
  this->m_CaseMap= new Case[height*width];
}


//////////OTHER METHODS//////////

int calculCoordX(int position){ // Du R

}

int calculCoordY(int position){ // Du R

}

int calculPosition(float x, float y){
  if (x==0){
    int caseX=0;
  } else{
    int caseX = (int)(x/3);
  }
return (int)caseX+(int)(3*y);
}

void Map::Scale(int heightPPM, int widthPPM){
    if (HeightPPM!=0 && widthPPM!=0){
        setheight(this->heightPPM*30); //donne hauteur de notre image de ref fois 30
        setWidth(this->widthPPM*30); //donne largeur de notre image de ref fois 30
    } else {
        printf("The picture does not have a proper size")
    }
}

void Map::readPPM(char* filename){
  int width;
  int height;
  char chaine[255];
  int size;

  // open the file to read just the header reading
	FILE *file = fopen(filename, "rb");

    if(!file){
      printf("ERROR READING PPM \n");
      return EXIT_FAILURE;
    }


    // read header
    fscanf(file,"%s\n", chaine);

    // comment
    do{
      fgets(chaine, 255, file);
    } while (chaine[0]=='#');

  	// read the rest of header
  	sscanf(chaine, "%d\n %d\n", &width, &height);
    // check to see if they were stored properly
    printf("Width: %d\n", width);
    printf("Height: %d\n", height);

    //int size = width * height;
    int size = width*height;

    this->setParams(height, width);

    // Read 255
    fscanf(file, "%s\n", chaine);

  // On met le reste dans un tableau de pixels
  unsigned char* data = new unsigned char[size]
	// unformatted read of binary pixel data
	while (fread(data, sizeof(int), width*height*3, file)) {
		printf("%s", data);
	} // end of for loop

  for (int y=0; y<height; y++){
    for (int x=0; x<width; x++){
      int pixel = (y*width*3)+x*3 // (Garder le x3 ? )
      int r = data[pixel];
      int v = data[pixel+1];
      int b = data[pixel+2];
      Case = new Case((x*30)+15,(y*30)+15,verifColor(r,v,b));
      this->m_CaseMap(calculPosition(x,y)) = Case; //

      // Dessiner le carré sur le truc openGL (GLBegin blablabla Mais COMMENT sans récupérer sdl surface ??)
    }
  }


    //puis for i = 4 à i<taille.tab
    //read tab[i] tab[i+1] tab[i+2] pour obtenir RVB de chaque pixel
    // avec cette info on trace en open-gl un carré de 30 par 30 pixel de la couleur souhaité au bon emplacement
    //comment gérer coordonnées ? ==> avec un compte de carré
    //on sait qu'on veut widthPPM carrés de large et heightPPM carrés de haut ==> permets de réaliser des boucles


    fclose(file);
}

void Map::initMap(){
this->readPPM("../images/map1.ppm");
GLuint mapTexture = 0;
string pathMap = "../images/map1.png";
mapTexture=loadTexture(pathMap);

glPushMatrix();
glTranslate(this->getPosition()->getX(),this->getPosition()->getY(),0);
drawPicture(mapTexture, this->getHeight(), this->getWidth()); // Taille tower
glPopMatrix();
}


ColorCase verifColor(int r, int v, int b){ // A compléter en fonction des couleurs
  if (r==? && v==? && b==?){
    return OUT;
  } else if (r==? && v==? && b==?){
    return IN;
  } else if (r==? && v==? && b==?){
    return BUILD ;
  } else {
    return PATH;
  }
}
