#pragma once

#include "Tile.hpp"
#include "Node.hpp"

class Map{
private:
  // Attributs
  int m_height;
  int m_width;
  Tile* m_TileMap[150];
  Node* m_listNodes;

public:

  Map(); //constructeur
  ~Map();

  //////GETTERS/////
  int getHeight();
  int getWidth();
  Tile *getTile(int position);
  Tile *getAllTiles();
  int getSizeTiles();
  Node* getListNodes();

  //////SETTERS/////
  void setHeight(int newHeight);
  void setWidth(int newWidth);
  void setTileMap(int Position, Tile *t);
  void setAllTiles(Tile *tab);
  void setParams(int height, int width);
  void setListNodes(Node* list);


  //////OTHERS//////

  int calculPosition(float x, float y); // Calcul la position de la tile dans le tableau en fonction des coordonnées du pixel
  void Scale( int heightPPM, int widthPPM); //créer carte de la taille souhaitée en fonction du plan fourni en ppm (échelle *100)
  ColorTile verifColor(int r, int v, int b);
  void readPPM(char* filename);
  Node* readITD(char* filename);
  bool verifGraph(Node* tabNodes);
  void initMap();
};
