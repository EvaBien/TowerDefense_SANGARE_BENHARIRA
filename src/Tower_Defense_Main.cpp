// MAIN //
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "../include/Game.hpp"
#include "../include/Window.hpp"

// ChangerCurseur

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

  bool TChecked = false;
  bool BChecked = false;
  bool 1Checked = false;
  bool 2Checked = false;
  bool 3Checked = false;
  bool 4Checked = false;
  int typeChecked = 0;
  SDL_Surface *cursor;
  SDL_Surface *image;


  /* EVENEMENT */
  SDL_Event e;
  while(SDL_PollEvent(&e))
  {

      switch(e.type)
      {

        case SDL_QUIT:
        myGame->gameOver();
        /* Redimensionnement fenetre */
        case SDL_VIDEORESIZE:
        reshape(&surface, e.resize.w, e.resize.h);
        break;

        /* Clic souris */
        case SDL_MOUSEBUTTONUP:
        printf("clic en (%d, %d)\n", e.button.x, e.button.y);
        break;

        /* Touche clavier */
        case SDL_KEYDOWN:
        printf("touche pressee (code = %d)\n", e.key.keysym.sym);
        switch(e.key.keysym.sym){

          /* TOUCHE Q */
          case SDLK_q:
          myGame->gameOver();
          break;

          /* TOUCHE ESC */
          case SDLK_ESCAPE:
          myGame->gameOver();
          break;

          /* TOUCHE T */
          case SDLK_t:
          if (TChecked == false && BChecked == false){
            TChecked = true;
            1Checked = true;
          } else if (TChecked ==false && BChecked == true){
            TChecked = true;
            BChecked = false;
          } else if (TChecked == true){
            TChecked = false;
          }
          break;

          /* TOUCHE B */
          case SDLK_b:
          if (BChecked == false && TChecked == false){
            BChecked = true;
            1Checked = true;
          } else if (BChecked ==false && TChecked == true){
            BChecked = true;
            TChecked = false;
          } else if (BChecked == true){
            BChecked = false;
          }
          break;

          /* TOUCHE 1 */
          case SDLK_1:

          1Checked = true;
          if (2Checked ==true){
            2Checked = false;
          }
          if (3Checked ==true){
            3Checked = false;
          }
          if (4Checked ==true){
            4Checked = false;
          }
          break;

          /*TOUCHE 2*/
          case SDLK_2:
          2Checked = true;
          if (1Checked ==true){
            1Checked = false;
          }
          if (3Checked ==true){
            3Checked = false;
          }
          if (4Checked ==true){
            4Checked = false;
          }
          break;

          /* TOUCHE 3*/
          case SDLK_3:
          3Checked = true;
          if (2Checked ==true){
            2Checked = false;
          }
          if (1Checked ==true){
            1Checked = false;
          }
          if (4Checked ==true){
            4Checked = false;
          }

          break;


          /* TOUCHE 4*/
          case SDLK_4:
          if (TChecked == false){
            4Checked = true;
            if (2Checked ==true){
              2Checked = false;
            }
            if (3Checked ==true){
              3Checked = false;
            }
            if (1Checked ==true){
              1Checked = false;
            }
          }
          break;


          /*DEFAULT*/
          default :
          break;
        }

        // Verif -> TChecked == false;
        // Tcheched -> true
        //Verif ->BChecked == true -> devient false
        // Seconde touche -> e.type = SDL_KEYDOWN
        // CASE : 1, 2, 3, 4
        // Changer curseur
        // If click -> construct (x, y,, towertype)
        // CASE : T -> false;

        default:
        break;
      }

    }


  }
