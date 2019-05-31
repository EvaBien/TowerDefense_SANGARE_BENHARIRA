#include <string>
#include "../include/Node.hpp"

using namespace std;

Node::Node(int type, float x, float y, int index, int successor, Map *map){
  if (type==1){
    this->type = IN;
  } else if (type==2){
    this->type = OUT;
  } else if (type==3){
    this->type = TWIST;
  } else {
    this->type = INTER;
  }

  this->index=index;
  this->successor=successor;
  this->map=map;
  this->m_tile = map->getTile(calculPosition(x*100,y*100));
}

Node::~Node(){};

//////GETTERS/////
Tile getTile(){
  return this->m_tile;
}

TypeNode getType(){
  return this->type;
}

int getIndex(){
  return this->index;
}
int getSuccessor(){
  return this->successor;
}

Map* getMap(){
  return this->map;
}

Node* getNext(){
  return this->next;
}

//////SETTERS/////
void setTile(Tile *c){
  this->m_tile = tile;
}

void setType(TypeNode type){
  this->type=type;
}

void setIndex(int index){
  this->index=index;
}

void setSuccessor(int successor){
  this->successor=successor;
}

void setMap(Map *map){
  this->map=map;
}

void setNext(Node *node){
  this->next=node;
}

//////////OTHERS/////////



///////////////////////////////////////////
/////////////// PATHS NODES ///////////////
//////////////////////////////////////////


//////GETTERS/////
int getLenght(){
  return this->m_lenght;
}
Node* getHead(){
  return this->head;
}
Node* getEnd(){
  return this->end;
}

//////SETTERS/////
void setLenght(int lenght){
  this->m_lenght=lenght;
}
void setHead(Node* node){
  this->head=node;
}
void setEnd(Node* node){
  this->end=node;
}

//////OTHERS/////

void addNode(NodeType type, float x, float y, int *successors);
void deleteNode(Node *node);
