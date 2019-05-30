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
  Game myGame = new Game();
  myGame->startGame();

  bool TChecked = false;
  bool BChecked = false;
  bool Checked1 = false;
  bool Checked2 = false;
  bool Checked3 = false;
  bool Checked4 = false;
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

          // ChangerCurseur

          //  //Standard cursor must be turned off
          //
          // image = SDL_LoadBMP("mouseTower.bmp"); //Load my cursor
          // image = SDL_LoadBMP("mouseBuilding.bmp"); //Load my cursor
          // SDL_ShowCursor(SDL_ENABLE); // Fait réapparaitre mon curseur

          //
          // cursor = SDL_DisplayFormatAlpha(image); //Set
          //
          // //Set the color as transparent
          // SDL_SetColorKey(cursor,SDL_SRCCOLORKEY|SDL_RLEACCEL,SDL_MapRGB(cursor->format,0x0,0x0,0x0));

          /* TOUCHE T */
          case SDLK_t:
          if (TChecked == false && BChecked == false){
            TChecked = true;
            Checked1 = true;
            SDL_ShowCursor( SDL_DISABLE );
            image = SDL_LoadBMP("../images/towerRed.bmp"); //Load my cursor
            cursor = SDL_DisplayFormatAlpha(image);

          } else if (TChecked ==false && BChecked == true){
            TChecked = true;
            BChecked = false;
            SDL_ShowCursor( SDL_DISABLE );
            image = SDL_LoadBMP("../images/towerRed.bmp"); //Load my cursor
            cursor = SDL_DisplayFormatAlpha(image);

          } else if (TChecked == true){
            TChecked = false;
            SDL_ShowCursor( SDL_ENABLE );

          }
          break;

          /* TOUCHE B */
          case SDLK_b:
          if (BChecked == false && TChecked == false){
            BChecked = true;
            Checked1 = true;
            SDL_ShowCursor( SDL_DISABLE );
            image = SDL_LoadBMP("../images/buildingRadar.bmp"); //Load my cursor
            cursor = SDL_DisplayFormatAlpha(image);

          } else if (BChecked ==false && TChecked == true){
            BChecked = true;
            TChecked = false;

            SDL_ShowCursor( SDL_DISABLE );
            image = SDL_LoadBMP("../images/buildingRadar.bmp"); //Load my cursor
            cursor = SDL_DisplayFormatAlpha(image);

          } else if (BChecked == true){
            BChecked = false;
            SDL_ShowCursor( SDL_ENABLE );

          }
          break;

          /* TOUCHE 1 */
          case SDLK_1:

          Checked1 = true;
          if (Checked2 ==true){
            Checked2 = false;
          }
          if (Checked3 ==true){
            Checked3 = false;
          }
          if (Checked4 ==true){
            Checked4 = false;
          }

          if (TChecked){
            SDL_ShowCursor( SDL_DISABLE );
            image = SDL_LoadBMP("../images/towerRed.bmp"); //Load my cursor
            cursor = SDL_DisplayFormatAlpha(image);
          } else if (BChecked){
            SDL_ShowCursor( SDL_DISABLE );
            image = SDL_LoadBMP("../images/buildingRadar.bmp"); //Load my cursor
            cursor = SDL_DisplayFormatAlpha(image);
          }
          break;

          /*TOUCHE 2*/
          case SDLK_2:
          Checked2 = true;
          if (Checked1 ==true){
            Checked1 = false;
          }
          if (Checked3 ==true){
            Checked3 = false;
          }
          if (Checked4 ==true){
            Checked4 = false;
          }
          if (TChecked){
            SDL_ShowCursor( SDL_DISABLE );
            image = SDL_LoadBMP("../images/towerGreen.bmp"); //Load my cursor
            cursor = SDL_DisplayFormatAlpha(image);
          } else if (BChecked){
            SDL_ShowCursor( SDL_DISABLE );
            image = SDL_LoadBMP("../images/buildingWeapon.bmp"); //Load my cursor
            cursor = SDL_DisplayFormatAlpha(image);
          }
          break;

          /* TOUCHE 3*/
          case SDLK_3:
          Checked3 = true;
          if (Checked2 ==true){
            Checked2 = false;
          }
          if (Checked1 ==true){
            Checked1 = false;
          }
          if (Checked4 ==true){
            Checked4 = false;
          }
          if (TChecked){
            SDL_ShowCursor( SDL_DISABLE );
            image = SDL_LoadBMP("../images/towerYellow.bmp"); //Load my cursor
            cursor = SDL_DisplayFormatAlpha(image);
          } else if (BChecked){
            SDL_ShowCursor( SDL_DISABLE );
            image = SDL_LoadBMP("../images/buildingStock.bmp"); //Load my cursor
            cursor = SDL_DisplayFormatAlpha(image);
          }

          break;


          /* TOUCHE 4*/
          case SDLK_4:
          if (BChecked == false){
            Checked4 = true;
            if (Checked2 ==true){
              Checked2 = false;
            }
            if (Checked3 ==true){
              Checked3 = false;
            }
            if (Checked1 ==true){
              Checked1 = false;
            }
          }
          if (TChecked){
            SDL_ShowCursor( SDL_DISABLE );
            image = SDL_LoadBMP("../images/towerBlue.bmp"); //Load my cursor
            cursor = SDL_DisplayFormatAlpha(image);
          }
          break;

          /*DEFAULT*/
          default :
          break;
        }


        /* Clic souris */
        case SDL_MOUSEBUTTONUP:
        printf("clic en (%d, %d)\n", e.button.x, e.button.y);


        if (TChecked && Checked1 == true){
          TowerType typeT = RED_LASER;
          myGame->constructTower(typeT, e.button.x, e.button.y);
        } else if (TChecked && Checked2 == true){
          TowerType typeT = GREEN_GRASS;
          myGame->constructTower(typeT, e.button.x, e.button.y);
        } else if (TChecked && Checked3 == true){
          TowerType typeT = YELLOW_GAMMELLE;
          myGame->constructTower(typeT, e.button.x, e.button.y);
        } else if (TChecked && Checked1 == true){
            TowerType typeT = BLUE_MILK;
          myGame->constructTower(typeT, e.button.x, e.button.y);
        } else if (BChecked && Checked1 == true){
          BuildingType typeB = RADAR;
          myGame->constructBuilding(typeB, e.button.x, e.button.y);
        } else if (BChecked && Checked2 == true){
          BuildingType typeB = WEAPON;
          myGame->constructBuilding(typeB, e.button.x, e.button.y);
        } else if (BChecked && Checked3 == true){
          BuildingType typeB = STOCK;
          myGame->constructBuilding(typeB, e.button.x, e.button.y);
        }
        break;

        default:
        break;
      }

    }


  }
