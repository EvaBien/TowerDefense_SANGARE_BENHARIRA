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
  this->m_case = map->getCase(calculPosition(x*100,y*100));
}

Node::~Node(){};

//////GETTERS/////
Case getCase(){
  return this->m_case;
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
void setCase(Case *c){
  this->m_case = case;
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
int getLenght();
Node* getHead();
Node* getEnd();

//////SETTERS/////
void setLenght(int lenght);
void setHead(Node* node);
void setEnd(Node* node);

//////OTHERS/////

void addNode(NodeType type, float x, float y, int *successors);
void deleteNode(Node *node);
