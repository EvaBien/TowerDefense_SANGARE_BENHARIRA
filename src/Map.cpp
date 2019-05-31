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

Tile Map::getTile(int position){
  return this->mTileMap[position];
}
Tile* Map::getAllTiles(){
  return this->m_TileMap;
}

int Map::getSizeTiles(){
  return this->getHeight()*this->getWidth();
}

PathNode Map::getlistNode(){
  return this->m_listNodes;
}
/////////SETTERS//////////

void Map::setHeight(int newHeight){
  this->m_height = newHeight; //Remplace valeur Height par une nouvelle
}

void Map::setWidth(int newWidth){
  this->m_width=newWidth; //Remplace valeur Width par une nouvelle
}

void Map::setTileMap(int position, Tile *tile){
  this->m_TileMap[position] = &tile;
}

void Map::setAllTiles(Tile *tab){
  this->m_TileMap=tab;
}

void Map::setParams(int height, int width){
  this->m_height=height;
  this->m_width=width;
  this->m_TileMap= new Tile[height*width];
}

PathNode Map::setListNodes(PathNode list){
  this->m_listNodes = list;
}

//////////OTHER METHODS//////////

int calculCoordX(int position){ // Du R

}

int calculCoordY(int position){ // Du R

}

int calculPosition(float x, float y){
  if (x==0){
    int tileX=0;
  } else{
    int tileX = (int)(x/3);
  }
  return (int)tileX+(int)(3*y);
}

void Map::Scale(int heightPPM, int widthPPM){
  if (HeightPPM!=0 && widthPPM!=0){
    setheight(this->heightPPM*100); //donne hauteur de notre image de ref fois 100
    setWidth(this->widthPPM*100); //donne largeur de notre image de ref fois 100
  } else {
    printf("The picture does not have a proper size")
  }
}


ColorTile verifColor(int r, int v, int b){ // A compléter en fonction des couleurs
  if (r==200 && v==0 && b==0){
    return OUT;
  } else if (r==0 && v==200 && b==0){
    return IN;
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
      int pixel = (y*width*3)+x*3; // (Garder le x3 ? )
      int r = data[pixel];
      int v = data[pixel+1];
      int b = data[pixel+2];
      Tile = new Tile((x*100)+50,(y*100)+50,verifColor(r,v,b));
      this->m_TileMap(calculPosition(x,y)) = Tile;
    }
  }
  fclose(file);
}


Node* Map::readITD(char* filename){

  // open the file to read
  FILE *file = fopen(filename, "r");

  //check that there is no error
  if(!file){
    printf("ERROR READING ITD \n");
    return EXIT_FAILURE;
  }

  char chaine[250];
  int nbNode;
  unsigned char* tabNode = new unsigned char[nbNode]

  //vérifie qu'on a ou non atteint la fin du document
  if  (fgets(chaine, 250, file) != NULL){

    bool reading = true;

    while (reading)	{
      // read header
      if (fscanf(file,"%s\n", chaine) != "@ITD1"){
        printf("ERROR, this file is not identified as an ITD \n");
      } else {
        // ne pas prendre en compte les comments
        do{
          fgets(chaine, 255, file);
        } while (chaine[0]=='#');

        for(int i=1; i<13; i++){
          sscanf(chaine, "%s\n", chaine);
        }
        nbNode = sscanf(chaine, "%d\n", chaine);
        do{
          fgets(chaine, 255, file);
        } while (chaine[0]=='#');

        // On met le reste dans un tableau de node TabNode[]
        for (int i = 1; i<nbNode; i++){
          int index;
          int type;
          int x;
          int y;
          int successors;
          sscanf(chaine, "%d\n %d\n %d\n %d\n %d\n", &index, &type, &x, &y, successors);
          tabNode[i] = new Node(x, y, type, successors, index, &this);
        }
        reading = false; //met fin à la lecture
      }
    }
  }

  fclose(file);
  return
}


void Map::initMap(){

  this->readPPM("../images/map1.ppm");
  Node* tabNode =this->readITD("../map.itd.txt");

  if (this->verifGraph()){

    PathNode listMap = new PathNode();
    listMap->m_lenght = tabNode.size();
    listMap->head = tabNode[0];
    listMap->end = tabNode[1];

    this->setListNodes(listMap);

    if(this->getListNodes() == NULL) {
      fprintf(stderr, "Unvalid map\n");
    }

    GLuint mapTexture = 0;
    string pathMap = "../images/map1.png";
    mapTexture=loadTexture(pathMap);

    glPushMatrix();
    glTranslate(this->getPosition()->getX(),this->getPosition()->getY(),0);
    drawPicture(mapTexture, this->getHeight(), this->getWidth());
    glPopMatrix();
  }
}
