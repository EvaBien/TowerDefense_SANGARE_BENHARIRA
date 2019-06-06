#include "Window.hpp"

#ifdef _WIN32
	#include <windows.h>
#endif
#include <fstream>
#include <glad/glad.h>
#include <SDL2/SDL.h>
#include <GL/glu.h>

SDL_Window* initWindow() {
	/* Init SDL */
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) != 0) {
		printf("Unable to init SDl ! \n");
		return nullptr;
	}

	/* Init OpenGL */
	SDL_GL_LoadLibrary(NULL);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);
	SDL_SetHint(SDL_HINT_RENDER_DRIVER, "opengl");
	SDL_GL_SetSwapInterval(1);

	/* Initialisation + Nom fenêtre*/
	static const unsigned int WINDOW_WIDTH = 1200;
	static const unsigned int WINDOW_HEIGHT = 1800;
	static const char WINDOW_TITLE[] = "IMACat Attack";
	SDL_Window* window = SDL_CreateWindow(
		WINDOW_TITLE,
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		WINDOW_WIDTH, WINDOW_HEIGHT,
		SDL_WINDOW_OPENGL
	);
	if (window == nullptr) {
		printf("Impossible d'ouvrir la fenetre ! \n");
	}

	/* Espace fenetre virtuelle */
	// static const float GL_VIEW_WIDTH = 1200;
	// static const float GL_VIEW_HEIGHT = 800;
	static const float GL_VIEW_SIZE = 150.;

	/* Nombre de bits par pixel de la fenetre */
	static const unsigned int BIT_PER_PIXEL = 32;

	/* Nombre minimal de millisecondes separant le rendu de deux images */
	static const Uint32 FRAMERATE_MILLISECONDS = 1000 / 60;

	/* Create OpenGl context */
	SDL_GLContext context = SDL_GL_CreateContext(window);
	if (context == nullptr) {
		printf("[SDL2] OpenGL context is null: %s \n", SDL_GetError());
		return nullptr;
	}

	/* Init Glad once the OpenGL context is valid */
	if (!gladLoadGLLoader(SDL_GL_GetProcAddress)) {
		printf("[Glad] Glad not init \n");
		return nullptr;
	}

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// glOrtho(0,WINDOW_WIDTH,WINDOW_HEIGHT,0,-1,1);
	// glMatrixMode(GL_MODELVIEW);
	gluOrtho2D(0, SDL_GetWindowSurface(window)->w, SDL_GetWindowSurface(window)->h, 0);


	// Blending
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	return window;
}

void readITD() {
	/* ifstream pour ouvrir fichier
	parcourir ligne par ligne
	en fonction info contenu dans ligne imbrication de if et différente action*/
}
