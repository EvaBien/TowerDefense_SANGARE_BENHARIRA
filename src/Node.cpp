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



}

Node::~Node(){};

//////GETTERS/////
Case getCase(){

}
TypeNode getType(){

}
int getSuccessor(){

}
Node* getNext(){

}

//////SETTERS/////
void setCase(Case c){

}
void setType(TypeNode type){

}
void setSuccessor(int successor){

}
void setNext(Node *node){

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
