#pragma once

class Map;
class Tile;

enum TypeNode{
  ENTREE,
  SORTIE,
  TWIST,
  INTER,
};

class Node{
private:
  // Attributs
  float m_x;
  float m_y;
  Tile *m_tile;
  TypeNode type;
  int index;
  int successor;
  Map *map;
  Node *next;



public:

  Node(int type, float x, float y, int index, int successor, Map* map); //constructeur
  Node();
  ~Node();

  //////GETTERS/////
  float getX();
  float getY();
  Tile *getTile();
  TypeNode getType();
  int getIndex();
  int getSuccessor();
  Map* getMap();
  Node* getNext();

  //////SETTERS/////
  void setX(float x);
  void setY(float y);
  void setTile (Tile *c);
  void setType(TypeNode type);
  void setType(int type);
  void setIndex(int index);
  void setSuccessor(int successor);
  void setMap(Map *map);
  void setNext(Node *node);
  //////OTHERS/////
};

class PathNode {

private:
  int m_lenght;
  Node *head;
  Node *end;

  public :
	  PathNode() {};
	  ~PathNode() {};

  //////GETTERS/////
  int getLenght();
  Node* getHead();
  Node* getEnd();

  //////SETTERS/////
  void setLenght(int lenght);
  void setHead(Node* node);
  void setEnd(Node* node);

  //////OTHERS/////

  void addNode(TypeNode type, Tile c, int successors);
  void deleteNode(Node *node);

};
