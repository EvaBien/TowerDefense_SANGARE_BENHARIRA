// MAIN //
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "../include/Game.hpp"
#include "../include/Window.hpp"

// ChangerCurseur
// SDL_Surface *cursor;
// SDL_Surface *image;
//
// SDL_ShowCursor( SDL_DISABLE ); //Standard cursor must be turned off
//
// image = SDL_LoadBMP("mouseTower.bmp"); //Load my cursor
// image = SDL_LoadBMP("mouseBuilding.bmp"); //Load my cursor
// SDL_ShowCursor(SDL_ENABLE); // Fait réapparaitre mon curseur

//
// cursor = SDL_DisplayFormat(image); //Set
//
// //Set the color as transparent
// SDL_SetColorKey(cursor,SDL_SRCCOLORKEY|SDL_RLEACCEL,SDL_MapRGB(cursor->format,0x0,0x0,0x0));

int main(int argc, char **argv) {

  SDL_Window* window = initWindow(); // Init fenêtre
  if (window == nullptr) {
    cout << "Error window init" << endl;
  }
  Game myGame = new Game();
  myGame->startGame();


        //   /* Boucle traitant les evenements */
        //   SDL_Event e;
        //   while(SDL_PollEvent(&e))
        //   {
        //       /* L'utilisateur ferme la fenetre : */
        //       if(e.type == SDL_QUIT)
        //       {
        //           loop = 0;
        //           break;
        //       }
        //
        //       /* L'utilisateur ferme la fenetre : */
  			// if(e.type == SDL_QUIT)
  			// {
  			// 	loop = 0;
  			// 	break;
  			// }
        //
  			// if(	e.type == SDL_KEYDOWN
  			// 	&& (e.key.keysym.sym == SDLK_q || e.key.keysym.sym == SDLK_ESCAPE))
  			// {
  			// 	loop = 0;
  			// 	break;
  			// }
        //
        //       /* Quelques exemples de traitement d'evenements : */
        //       switch(e.type)
        //       {
        //           /* Redimensionnement fenetre */
  			// 	case SDL_VIDEORESIZE:
        //               reshape(&surface, e.resize.w, e.resize.h);
        //               break;
        //
        //           /* Clic souris */
        //           case SDL_MOUSEBUTTONUP:
        //               printf("clic en (%d, %d)\n", e.button.x, e.button.y);
        //
        //               switch(e.button.button)
        //               {
        //                   case SDL_BUTTON_LEFT:
        //                       beta += 5.;
        //                       break;
        //
        //                   case SDL_BUTTON_RIGHT:
        //                       beta -= 5.;
        //                       break;
        //
        //                   default:
        //                       break;
        //               }
        //               break;
        //
        //           /* Touche clavier */
        //           case SDL_KEYDOWN:
        //               printf("touche pressee (code = %d)\n", e.key.keysym.sym);
        //               break;
        //
        //           default:
        //               break;
        //       }
        //   }

}


/*
PROBLEME :

- Quand on tue un monstre on veut qu'il sorte du vecteur et qu'il
donne de l'argent à la m_cagnotte
- La cagnotte et le vecteur sont des attributs de Game
- Game inclus CatMonster

==> ajouter entity.hpp
read ITD à faire


*/
