// MAIN //
#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "../include/Game.hpp"
#include "../include/Window.hpp"


int main(int argc, char **argv) {

  SDL_Window* window = initWindow(); // Init fenêtre
  if (window == nullptr) {
    cout << "Error window init" << endl;
  }
  Game myGame = new Game();

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
      Mix_FreeMusic(musique); //Libération de la musique
      Mix_CloseAudio();
      SDL_DestroyWindow(window);
      break;

      /* Redimensionnement fenetre */
      case SDL_VIDEORESIZE:
      reshape(&surface, e.resize.w, e.resize.h);
      break;

      /* Touche clavier */
      case SDL_KEYDOWN:
      printf("touche pressee (code = %d)\n", e.key.keysym.sym);
      switch(e.key.keysym.sym){

        /*TOUCHE SPACE*/
        case SDLK_SPACE:
        if (myGame->getFinish()==true){
          myGame->startGame();
          if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer
          {
            printf("Erreur de son %s", Mix_GetError());
          }
          Mix_Music *musique; //Création du pointeur de type Mix_Music
          musique = Mix_LoadMUS("./sound/NyanCat.mp3"); //Chargement de la musique
          Mix_PlayMusic(musique, -1); //Jouer infiniment la musique
        }
        break;

        /* TOUCHE Q */
        case SDLK_q:
        myGame->gameOver();
        Mix_FreeMusic(musique); //Libération de la musique
        Mix_CloseAudio();
        SDL_DestroyWindow(window);

        break;

        /* TOUCHE ESC */
        case SDLK_ESCAPE:
        myGame->gameOver();
        Mix_FreeMusic(musique); //Libération de la musique
        Mix_CloseAudio();
        SDL_DestroyWindow(window);
        break;

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




/*******************************************************/
/************************ TO DO  ***********************/
/*******************************************************/

/************************ DISPLAY *********************/
/*
- Cursors
- Map
- Cat
- Tower
- Building
*/

/********************** GRAPH/PATH *******************/
/*
- Graph-Nodes functions
- Move Monster() (bouger + chercher noeud)
- Brassenham
- Dijkstra
- Read ITD
- CHeck Map x ITD
*/

/************************ OTHER *********************/
/*
- Sound : PlaySound("myMusic.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
- Monster Disappear
- Money
*/

//// FONCTION TEXT /////
/*glRasterPos2f(x, y);
for (c = s; *c != '\0'; c++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c); // Affiche chaque caractère de la chaîne

// Réinitialise la position du premier caractère de la chaîne
glRasterPos2f(0, 0);
}*/



/*******************************************************/
/*******************************************************/
/*******************************************************/
