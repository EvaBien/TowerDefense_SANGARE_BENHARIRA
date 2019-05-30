#include "../include/Window.hpp"
#include <fstream>

using namespace std;


SDL_Window* initWindow(){
  /* Initialisation + Nom fenêtre*/
  static const unsigned int WINDOW_WIDTH = 1200;
  static const unsigned int WINDOW_HEIGHT = 1800;
  static const char WINDOW_TITLE[] = "IMACat Attack";
  SDL_Window* window = SDL_CreateWindow(WINDOW_TITLE,SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,WINDOW_WIDTH,WINDOW_HEIGHT, SDL_WINDOW_OPENGL);

  /* Espace fenetre virtuelle */
  // static const float GL_VIEW_WIDTH = 1200;
  // static const float GL_VIEW_HEIGHT = 800;
  static const float GL_VIEW_SIZE = 150.;

  /* Nombre de bits par pixel de la fenetre */
  static const unsigned int BIT_PER_PIXEL = 32;

  /* Nombre minimal de millisecondes separant le rendu de deux images */
  static const Uint32 FRAMERATE_MILLISECONDS = 1000 / 60;


  //// Contexte OpenGL ////
  SDL_GLContext context =  SDL_GL_CreateCONTEXT(window);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  // glOrtho(0,WINDOW_WIDTH,WINDOW_HEIGHT,0,-1,1);
  // glMatrixMode(GL_MODELVIEW);
 gluOrtho2D(0, SDL_GetWindowSurface(window)->w, SDL_GetWindowSurface(window)->h, 0);


  // Blending
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

  return window;
}

void reshape(SDL_Surface** surface, unsigned int width, unsigned int height)
{
    SDL_Surface* surface_temp = SDL_SetVideoMode(
        width, height, BIT_PER_PIXEL,
        SDL_OPENGL | SDL_GL_DOUBLEBUFFER | SDL_RESIZABLE);
    if(NULL == surface_temp)
    {
        fprintf(
            stderr,
            "Erreur lors du redimensionnement de la fenetre.\n");
        exit(EXIT_FAILURE);
    }
    *surface = surface_temp;

    glViewport(0, 0, (*surface)->w, (*surface)->h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
}

void readITD(){
    /* ifstream pour ouvrir fichier
    parcourir ligne par ligne
    en fonction info contenu dans ligne imbrication de if et différente action*/
}
