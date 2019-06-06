#include "Map.hpp"

#include <string>
#include <glad/glad.h>

#include "TextureController.hpp"

Map::Map(){};
Map::~Map(){};

//////////GETTERS//////////

int Map::getHeight(){
  return this->m_height;
}

int Map::getWidth(){
  return this->m_width;
}

Tile* Map::getTile(int position){
  return this->m_TileMap[position];
}
Tile* Map::getAllTiles(){
  // return this->m_TileMap;
	return nullptr;
}

int Map::getSizeTiles(){
  return this->getHeight()*this->getWidth();
}

Node* Map::getListNodes() {
  // return this->m_listNodes;
	return nullptr;
}
/////////SETTERS//////////

void Map::setHeight(int newHeight){
  this->m_height = newHeight; //Remplace valeur Height par une nouvelle
}

void Map::setWidth(int newWidth){
  this->m_width=newWidth; //Remplace valeur Width par une nouvelle
}

void Map::setTileMap(int position, Tile *tile){
  this->m_TileMap[position] = tile;
}

void Map::setAllTiles(Tile *tab){
  // this->m_TileMap=tab;
}

void Map::setParams(int height, int width){
  this->m_height=height;
  this->m_width=width;
 //  this->m_TileMap= new Tile[height*width];
}

void Map::setListNodes(Node* list){
  this->m_listNodes = list;
}

//////////OTHER METHODS//////////

int  Map::calculPosition(float x, float y){
int tileX = 0;
  if (x==0){
    tileX=0;
  } else{
    tileX = (int)(x/3);
  }
  return (int)tileX+(int)(3*y);
}

void Map::Scale(int heightPPM, int widthPPM) {
  if (heightPPM != 0 && widthPPM != 0) {
    //setheight(heightPPM*100); //donne hauteur de notre image de ref fois 100
    //setWidth(widthPPM*100); //donne largeur de notre image de ref fois 100
  } else {
	  printf("The picture does not have a proper size");
  }
}


ColorTile  Map::verifColor(int r, int v, int b){ // A compléter en fonction des couleurs
  if (r==200 && v==0 && b==0){
    return EXIT;
  } else if (r==0 && v==200 && b==0){
    return ENTRY;
  } else if (r==255 && v==200 && b==200){
    return BUILD;
  } else if (r==255 && v==255 && b==255){
    return PATH;
  } else if (r==0 && v==0 && b==0){
    return NODE;
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
  size = width*height;

  this->setParams(height, width);

  // Read 255
  fscanf(file, "%s\n", chaine);

  // On met le reste dans un tableau de pixels
  unsigned char* data = new unsigned char[size];
  // unformatted read of binary pixel data

  while (fread(data, sizeof(int), width*height*3, file)) {
    printf("%s", data);
  } // end of for loop


  for (int y=0; y<height; y++){
    for (int x=0; x<width; x++){

      printf(" je suis dans ma boucle \n");

      int pixel = (y*width*3)+x*3; // (Garder le x3 ? )
      int r = data[pixel];
      int v = data[pixel+1];
      int b = data[pixel+2];
      Tile* tile = new Tile((x*100)+50,(y*100)+50,verifColor(r,v,b)); // Tile tile au lieu de Tile* --> Probleme ici
      this->m_TileMap[calculPosition(x,y)] = tile;

    }
  }
  fclose(file);
}


Node* Map::readITD(char* filename){

  // open the file to read
  FILE *file = fopen(filename, "r");

  //check that there is no error
  if(!file){
    printf("ERROR OPEN ITD \n");
    return NULL;
  }

  char chaine[250];
  int nbNode;
  // Node* tabNode = new Node(0, 0, 0); // Remplacer char par Node !
  Node* tabNode = nullptr;

  //vérifie qu'on a ou non atteint la fin du document
  if (fgets(chaine, 250, file) == NULL){
    printf("ERROR : UNREADABLE FILE ITD");
    exit(EXIT_FAILURE);
    return NULL;
  }

  // read header
  //////////// PREMIERE LIGNE : @ITD 1 ///////////////
  /*
  if (fscanf(file,"%s\n", chaine) != "@ITD 1"){
    printf("ERROR, this file is not identified as an ITD \n");
    exit(EXIT_FAILURE);
    return NULL;
  }
  */

  // ne pas prendre en compte les comments
  //////////// DEUXIEME LIGNE : COMMENTS ///////////////
  do{
    fgets(chaine, 255, file);
  } while (chaine[0]=='#');


  //////////// SAUT LIGNE 3 A 10 ///////////////
  for(int i=0; i<7; i++){
    sscanf(chaine, "%s\n", chaine);
    printf("Verif Chaine : %s \n", chaine);
  }
  nbNode = sscanf(chaine, "%d\n", chaine);
  do{
    fgets(chaine, 255, file);
  } while (chaine[0]=='#');

  //On met le reste dans un tableau de node TabNode[]
  /////////////// LIGNES NODES ///////////////////
  int i=0;
  while(fgets(chaine, 255, file) != NULL){

    int index;
    int type;
    int x;
    int y;
    int successors;
    sscanf(chaine, "%d\n %d\n %d\n %d\n %d\n", index, type,(float)(x*100.0+50.0), (float)(y*100.0+50.0), successors); // OU ajouter les & devant les variable
    // tabNode[i] = new Node(x, y, type, successors, index, &this);
    i++;
  }

  fclose(file);
  return nullptr;
}

bool Map::verifGraph(Node *tabNode){
	/*
  int size = tabNode.size();

  for (int i=0; i<size; i++){
    float x = tabNode[i]->getX();
    float y = tabNode[i]->getY();
    int position = calculPosition(x,y);
    Tile tile = this->getTile(position);

    if (tile->getType() == NODE && tabNode[i]->getType()==TWIST || tile->getType() == NODE && tabNode[i]->getType()==INTER || tile->getType() == EXIT && tabNode[i]->getType()== SORTIE || tile->getType() == ENTRY && tabNode[i]->getType()==ENTREE){
      tabNode[i]->setCase(case);
    } else {
      printf("Le node %d pour la position X=%d & Y=%d est faux", i, x, y);
      return false;
    }
  }
  */
  return true;
}


void Map::initMap(){

  this->readPPM("images/map1.ppm");
  Node* tabNode = this->readITD("data/map1.itd");

  if (this->verifGraph(tabNode)){


    this->setListNodes(tabNode);

    if(this->getListNodes() == NULL) {
      fprintf(stderr, "Unvalid map\n");
    }

    GLuint mapTexture = 0;
    std::string pathMap = "images/map1.png";
    mapTexture = loadTexture(pathMap.c_str());

    glPushMatrix();
    glTranslatef(0,0,0); // 1500 x 1000;
    // drawPicture(mapTexture, this->getHeight(), this->getWidth());
    glPopMatrix();
  }
}
