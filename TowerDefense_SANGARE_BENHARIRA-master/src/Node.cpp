#include "Node.hpp"

#include <string>

Node::Node(int type, float x, float y, int index, int successor, Map *map){
  if (type==1){
    this->type = ENTREE;
  } else if (type==2){
    this->type = SORTIE;
  } else if (type==3){
    this->type = TWIST;
  } else {
    this->type = INTER;
  }

  this->index=index;
  this->successor=successor;
  this->map=map;
  this->m_x = x;
  this->m_y = y;
}

Node::Node();

Node::~Node(){};

//////GETTERS/////
float Node::getX(){
  return this->m_x;
}

float Node::getY(){
  return this->m_y;
}

Tile* Node::getTile(){
  return this->m_tile;
}

TypeNode Node::getType(){
  return this->type;
}

int Node::getIndex(){
  return this->index;
}
int Node::getSuccessor(){
  return this->successor;
}

Map* Node::getMap(){
  return this->map;
}

Node* Node::getNext(){
  return this->next;
}


//////SETTERS/////
void Node::setX(float x){
  this->m_x=x;
}

void Node::setY(float y){
  this->m_y=y;
}

void Node::setTile(Tile *c){
  this->m_tile = tile;
}

void Node::setType(TypeNode type){
  this->type=type;
}

void Node::setType(int type){
  if (type==1){
    this->type = ENTREE;
  } else if (type==2){
    this->type = SORTIE;
  } else if (type==3){
    this->type = TWIST;
  } else {
    this->type = INTER;
  }
}

void Node::setIndex(int index){
  this->index=index;
}

void Node::setSuccessor(int successor){
  this->successor=successor;
}

void Node::setMap(Map *map){
  this->map=map;
}

void Node::setNext(Node *node){
  this->next=node;
}

//////////OTHERS/////////



///////////////////////////////////////////
/////////////// PATHS NODES ///////////////
//////////////////////////////////////////


//////GETTERS/////


int PathNode::getLenght(){
  return this->m_lenght;
}
Node* PathNode::getHead(){
  return this->head;
}
Node* PathNode::getEnd(){
  return this->end;
}

//////SETTERS/////
void PathNode::setLenght(int lenght){
  this->m_lenght=lenght;
}
void PathNode::setHead(Node* node){
  this->head=node;
}
void PathNode::setEnd(Node* node){
  this->end=node;
}

//////OTHERS/////

void PathNode::addNode(TypeNode type, Tile c, int successors);
void PathNode::deleteNode(Node *node);
