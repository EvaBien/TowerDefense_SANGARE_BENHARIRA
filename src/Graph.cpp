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

  // read header
  fscanf(file,"%s\n", chaine);

  // comment
  do{
    fgets(chaine, 255, file);
  } while (chaine[0]=='#');

  // read the rest of header
  sscanf(chaine, "%d\n %d\n", &width, &height);
  // check to see if they were stored properly
  printf("Width: %d\n", width);
  printf("Height: %d\n", height);

  // Read 255
  fscanf(file, "%s\n", chaine);

  // On met le reste dans un tableau de pixels
  unsigned char* data = new unsigned char[size]
	// unformatted read of binary pixel data
	while (fread(data, sizeof(int), width*height*3, file)) {
		printf("%s", data);
	} // end of for loop

  fclose(file);
}

void Graph::initGraph(){
  this->readITD("");
}
