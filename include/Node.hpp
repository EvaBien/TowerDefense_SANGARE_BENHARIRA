#ifndef DEF_NODE
#define DEF_NODE

#include "Case.hpp"

class Map;
class Case;

enum TypeNode{
  ENTREE,
  SORTIE,
  TWIST,
  INTER,
};

class Node{
private:
  // Attributs
  Case *m_case;
  TypeNode type;
  int index;
  int successor;
  Map *map;
  Node *next;



public:

  Node(int type, float x, float y); //constructeur
  ~Node();

  //////GETTERS/////
  Case getCase();
  TypeNode getType();
  int getIndex();
  int getSuccessor();
  Map* getMap();
  Node* getNext();

  //////SETTERS/////
  void setCase (Case *c);
  void setType(TypeNode type);
  void setIndex(int index);
  void setSuccessor(int successor);
  void setMap(Map *map);
  void setNext(Node *node);
  //////OTHERS/////
};

class PathNode{

private:
  int m_lenght;
  Node *head;
  Node *end;

  public :
  PathNode();
  ~PathNode();

  //////GETTERS/////
  int getLenght();
  Node* getHead();
  Node* getEnd();

  //////SETTERS/////
  void setLenght(int lenght);
  void setHead(Node* node);
  void setEnd(Node* node);

  //////OTHERS/////

  void addNode(TypeNode type, Case c, int *successors);
  void deleteNode(Node *node);

};


#endif
