// MAIN //
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "../include/Game.hpp"
#include "../include/Window.hpp"



int main(int argc, char **argv) {

  SDL_Window* window = initWindow(); // Init fenêtre
  if (window == nullptr) {
    cout << "Error window init" << endl;
  }
  startGame();



  /* Echange du front et du back buffer : mise a jour de la fenetre */
          SDL_GL_SwapBuffers();

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
