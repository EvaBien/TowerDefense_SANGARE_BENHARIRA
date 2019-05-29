#include <string>
#include "../include/Graph.hpp"

using namespace std;

Graph::Graph(){}

Graph::~Graph(){};

//////////GETTERS//////////



/////////SETTERS//////////



//////////OTHER METHODS//////////


void Graph::readITD(char* filename){
  int width;
  int height;
  char chaine[255];
  int size;

  // open the file to read just the header reading
	FILE *file = fopen(filename, "rb");

    if(!file){
      printf("ERROR READING PPM \n");
      return EXIT_FAILURE;
    }


    // read hearder
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

    //int size = width * height;
    int size = width*height;

    this->setParams(height, width);

    // Read 255
    fscanf(file, "%s\n", chaine);

  // On met le reste dans un tableau de pixels
  unsigned char* data = new unsigned char[size
	// unformatted read of binary pixel data
	while (fread(data, sizeof(int), width*height*3, file)) {
		printf("%s", data);
	} // end of for loop

    for (int y=0; y<height; y++){
    for (int x=0; x<width; x++){
        int pixel = (y*width*3)+x*3 // (Garder le x3 ? )
        int r = data[pixel];
        int v = data[pixel+1];
        int b = data[pixel+2];
        Case = new Case((x*30)+15,(y*30)+15,verifColor(r,v,b));
        this->m_CaseMap(calculPosition(x,y)) = Case; //

        // Dessiner le carré sur le truc openGL (GLBegin blablabla Mais COMMENT sans récupérer sdl surface ??)
    }
    }


    //puis for i = 4 à i<taille.tab
    //read tab[i] tab[i+1] tab[i+2] pour obtenir RVB de chaque pixel
    // avec cette info on trace en open-gl un carré de 30 par 30 pixel de la couleur souhaité au bon emplacement
    //comment gérer coordonnées ? ==> avec un compte de carré
    //on sait qu'on veut widthPPM carrés de large et heightPPM carrés de haut ==> permets de réaliser des boucles


    fclose(file);
}

void Graph::initGraph(){
    this->readITD("");
}
