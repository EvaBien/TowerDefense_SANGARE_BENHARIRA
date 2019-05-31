#include <string>
#include "../include/Graph.hpp"

using namespace std;

Graph::Graph(){}

Graph::~Graph(){};

//////////GETTERS//////////



/////////SETTERS//////////



//////////OTHER METHODS//////////


int* Graph::readITD(char* filename){

  // open the file to read
	FILE *file = fopen(filename, "r");

  //check that there is no error
  if(!file){
    printf("ERROR READING ITD \n");
    return EXIT_FAILURE;
  }

  char tabNode[nbNode];
  //vérifie qu'on a ou non atteint la fin du document
  reading = (fgets(tabNode, nbNode, file) != NULL);

  while (reading)
  {
    if (tabNode[0] != '#'){
      
    }
  }
  
  //lire ligne par ligne donc entre chaque \n
  //s'il y a un # sur la ligne ==> ne pas la prendre en compte
  //SINON chercher char et lui associer triplet RVB
  //si juste un chiffre = nb neud
  //si plusieurs chiffre : premier = indice du noeud 
  // ==> on classe info associées dans un tableau ?
  // ie tant que ligne droite récup info revient à sauter de 5 en 5 case d'un tableau

  fclose(file);
  return
}

void Graph::initGraph(){
  this->readITD("");
}
