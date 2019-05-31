#ifndef DEF_MAP
#define DEF_MAP
#include "Tile.hpp"
#include "Node.hpp"

class Map{
private:
  // Attributs
  int m_height;
  int m_width;
  Tile m_TileMap[150];
  PathNode m_listNodes;
  
public:

  Map(); //constructeur
  ~Map();

  //////GETTERS/////
  int getHeight();
  int getWidth();
  Tile getTile(int position);
  Tile *getAllTiles();
  int getSizeTiles();
  PathNode getListNodes();

  //////SETTERS/////
  void setHeight();
  void setWidth();
  void setTileMap(int Position, Tile *c);
  void setAllTiles(Tile *tab);
  void setParams(int height, int width);
  void setListNodes(PathNode list);


  //////OTHERS//////

  int calculCoordX(int position);
  int calculCoordY(int position);
  int calculPosition(float x, float y); // Calcul la position de la tile dans le tableau en fonction des coordonnées du pixel
  void Scale( int heightPPM, int widthPPM); //créer carte de la taille souhaitée en fonction du plan fourni en ppm (échelle *100)
  ColorTile verifColor(int r, int v, int b);
  void readPPM(char* filename);
  Node* readITD(char* filename);
  bool verifGraph(Node* tabNodes);
  void initMap();
};

#endif
