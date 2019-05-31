#include <string>
#include "../include/Graph.hpp"
#include "../include/Node.cpp"

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

	char chaine[250];
	int nbNode;
	unsigned char* tabNode = new unsigned char[nbNode]

	//vérifie qu'on a ou non atteint la fin du document
	reading = (fgets(chaine, 250, file) != NULL);

	while (reading)
	{
		// read header
		if (fscanf(file,"%s\n", chaine) != "@ITD1"){
			printf("ERROR, this file is not identified as an ITD \n");
		} else {
			// ne pas prendre en compte les comments
			do{
				fgets(chaine, 255, file);
			} while (chaine[0]=='#');
			for(int i=1, i<13, i++){
				sscanf(chaine, "%s\n", chaine);
			}
			nbNode = sscanf(chaine, "%d\n", chaine);
			do{
				fgets(chaine, 255, file);
			} while (chaine[0]=='#');

			// On met le reste dans un tableau de node TabNode[]
			for (int i = 1, i<nbNode, i++){
				int index;
				int type;
				int x;
				int y;
				int successors;
				sscanf(chaine, "%d\n %d\n %d\n %d\n %d\n", &index, &type, &x, &y, successors);
				tabNode[i] = new Node(x, y, type, successors, index, &this);
			}
			reading = 0; //met fin à la lecture
		}

		fclose(fp);
		return tabNode;
	}

	//lire ligne par ligne donc entre chaque \n
	//s'il y a un # sur la ligne ==> ne pas la prendre en compte
	//SINON chercher char et lui associer triplet RVB
	//si juste un chiffre = nb neud
	//si plusieurs chiffre : premier = indice du noeud
	// ==> on classe info associées dans un tableau ?
	// ie tant que ligne droite récup info revient à sauter de 5 en 5 tile d'un tableau

	fclose(file);
	return
}

void Graph::initGraph(){
	this->readITD("");
}
