#include <string>
#include "../include/Graph.hpp"

using namespace std;

Graph::Graph(){}

Graph::~Graph(){};

//////////GETTERS//////////



/////////SETTERS//////////



//////////OTHER METHODS//////////


void Graph::readITD(char* filename){

  // open the file to read
	FILE *file = fopen(filename, "r");

  //check that there is no error
  if(!file){
    printf("ERROR READING ITD \n");
    return EXIT_FAILURE;
  }

  //lire ligne par ligne donc entre chaque \n
  //s'il y a un # sur la ligne ==> ne pas la prendre en compte
  //SINON chercher char et lui associer triplet RVB
  //si juste un chiffre = nb neud
  //si plusieurs chiffre : premier = indice du noeud 
  // ==> on classe info associées dans un tableau ?
  // ie tant que ligne droite récup info revient à sauter de 5 en 5 case d'un tableau

  fclose(file);
}

void Graph::initGraph(){
  this->readITD("");
}
