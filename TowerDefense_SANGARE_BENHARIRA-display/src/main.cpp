#ifdef _WIN32
#include <windows.h>
#endif
#define _USE_MATH_DEFINES
#include <cmath>
#include <SDL2/SDL.h>
#include <glad/glad.h>
#include <stdlib.h>
#include <stdio.h>
#include <GL/glu.h>
#include <GL/gl.h>

#include "../include/init.hpp"
#include "../include/tower.hpp"
#include "../include/building.hpp"
#include "../include/catMonster.hpp"
#include "../include/map.hpp"
#include "../include/textures.hpp"



static const Uint32 FRAMERATE_MILLISECONDS = 1000 / 60;

int main(int argc, char **argv) {
  SDL_Window* window = ImaCatAttack::init();
  if (window == nullptr) {
    printf("Error window init");
  }

  /////////// CHARGER IMAGES ////////////////
  //map
  const char map_path[] = "./images/MapCat.png";
  GLuint maptexture;
  maptexture = initTexture (map_path);

  //TOWER PATHS //
  const char tower_red_path[] = "./images/towerRed.png";
  const char tower_blue_path[] = "./images/towerBlue.png";
  const char tower_yellow_path[] = "./images/towerYellow.png";
  const char tower_green_path[] = "./images/towerGreen.png";
  //BUILDING PATHS //
  const char building_radar_path[] = "./images/buildingRadar.png";
  const char building_weapon_path[] = "./images/buildingWeapon.png";
  const char building_stock_path[] = "./images/buildingStock.png";

  /////////////// ENTITES & VARIABLES /////////////

  // Map
  Map myMap("./data/map1.itd");

  std::vector<CatMonster*> catMonsters;
  std::vector<Tower*> towers;
  std::vector<Building*> buildings;
  bool TChecked = false;
  bool BChecked = false;
  bool Checked1 = false;
  bool Checked2 = false;
  bool Checked3 = false;
  bool Checked4 = false;
  bool startPic = true;

  bool loop = true;
  while (loop) {
    Uint32 startTime = SDL_GetTicks();
    glColor4f(255, 255, 255, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glBindTexture(GL_TEXTURE_2D, maptexture);
    glBegin(GL_QUADS);
    glTexCoord2f(0, 1); glVertex2f(0, WINDOW_HEIGHT);   // bas gauche
    glTexCoord2f(1, 1); glVertex2f((WINDOW_WIDTH), WINDOW_HEIGHT);    // bas droite
    glTexCoord2f(1, 0); glVertex2f((WINDOW_WIDTH), 0);     // haut droite
    glTexCoord2f(0, 0); glVertex2f(0, 0);    // haut gauche
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);


    ///////// UPDATE ENTITES ////////
    for (Tower* tower : towers) {
      if(tower->getType()==RED_LASER){
        tower->update(tower_red_path);
      } else if(tower->getType()==GREEN_GRASS){
        tower->update(tower_green_path);
      } else if(tower->getType()==YELLOW_GAMMELLE){
        tower->update(tower_yellow_path);
      } else if(tower->getType()==BLUE_MILK){
        tower->update(tower_blue_path);
      }
    }
    for (CatMonster* catMonster : catMonsters) {
      catMonster->update();
    }

    for (Building* building : buildings) {
      if(building->getType()==RADAR){
        building->update(building_radar_path);
      } else if(building->getType()==WEAPON){
        building->update(building_weapon_path);
      } else if(building->getType()==STOCK){
        building->update(building_stock_path);
      }
    }

    SDL_GL_SwapWindow(window);
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT) {
        loop = false;
        break;
      }

      switch (e.type) {


        case SDL_QUIT:
        printf("Demande de quitter \n");
        /* Cleanup */
        SDL_DestroyWindow(window);
        SDL_Quit();
        for (Tower* tower : towers) {
          delete tower;
        }
        for (CatMonster* catMonster : catMonsters) {
          delete catMonster;
        }
        for (Building* building : buildings) {
          delete building;
        }

        return EXIT_SUCCESS;
        break;

        /* Redimensionnement fenetre */
        case SDL_WINDOWEVENT_RESIZED:
        // reshape(&surface, e.resize.w, e.resize.h);
        break;


        case SDL_KEYDOWN:
        printf("touche pressee (code = %d)\n", e.key.keysym);

        switch(e.key.keysym.sym){

          /* TOUCHE Q */
          case SDLK_q:
          printf("Demande de quitter \n");
          /* Cleanup */
          SDL_DestroyWindow(window);
          SDL_Quit();
          for (Tower* tower : towers) {
            delete tower;
          }
          for (CatMonster* catMonster : catMonsters) {
            delete catMonster;
          }
          for (Building* building : buildings) {
            delete building;
          }

          return EXIT_SUCCESS;

          break;

          /* TOUCHE ESC */
          case SDLK_ESCAPE:
          printf("Demande de quitter \n");
          /* Cleanup */
          SDL_DestroyWindow(window);
          SDL_Quit();
          for (Tower* tower : towers) {
            delete tower;
          }
          for (CatMonster* catMonster : catMonsters) {
            delete catMonster;
          }
          for (Building* building : buildings) {
            delete building;
          }

          return EXIT_SUCCESS;
          break;

          /* TOUCHE T */
          case SDLK_t:
          if (TChecked == false && BChecked == false){
            TChecked = true;
            Checked1 = true;
          } else if (TChecked ==false && BChecked == true){
            TChecked = true;
            BChecked = false;
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
          } else if (BChecked ==false && TChecked == true){
            BChecked = true;
            TChecked = false;
          } else if (BChecked == true){
            BChecked = false;
            SDL_ShowCursor( SDL_ENABLE );
          }
          break;

          /* TOUCHE 1 */
          case 	SDLK_KP_1:
          printf("Tu veux un type 1 ! \n");
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
          } else if (BChecked){
          }
          break;

          /*TOUCHE 2*/
          case SDLK_KP_2:
          printf("Tu veux un type 2 ! \n");
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
            printf("You want a GRASS TOWER\n");
          } else if (BChecked){
          }
          break;

          /* TOUCHE 3*/
          case SDLK_KP_3:
          printf("Tu veux un type 3 ! \n");
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
            printf("You want a GAMMELLE TOWER\n");
          } else if (BChecked){
          }

          break;


          /* TOUCHE 4*/
          case SDLK_KP_4:
          printf("Tu veux un type 4 ! \n");
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
            printf("Tu veux une tour Milk \n");
          }
          break;

          /*DEFAULT*/
          default :
          break;
        }

        break;

        /* Clic souris */
        case SDL_MOUSEBUTTONUP:
        {
          printf("clic en (%d, %d)\n", e.button.x, e.button.y);


          glm::vec2 gridPos = myMap.windowToGrid((float) e.button.x, (float) e.button.y);
          MapTile tile = myMap.getTile(gridPos.x, gridPos.y);
          if (tile == MapTile::constructible) {
            glm::vec2 winPos = myMap.gridToWindow(gridPos.x, gridPos.y);
            glm::vec2 center = myMap.gridToWindow(1, 1);
            center /= 2;
            winPos += center;

            if (TChecked && Checked1 == true){
              TowerType typeT = RED_LASER;
              Tower* tower = new Tower(typeT, winPos.x, winPos.y);
              towers.push_back(tower);
              tower->update(tower_red_path);
              myMap.setTile(gridPos.x, gridPos.y, MapTile::locked);
            } else if (TChecked && Checked2 == true){
              TowerType typeT = GREEN_GRASS;
              Tower* tower = new Tower(typeT, winPos.x, winPos.y);
              towers.push_back(tower);
              tower->update(tower_green_path);
              myMap.setTile(gridPos.x, gridPos.y, MapTile::locked);
            } else if (TChecked && Checked3 == true){
              TowerType typeT = YELLOW_GAMMELLE;
              Tower* tower = new Tower(typeT, winPos.x, winPos.y);
              towers.push_back(tower);
              tower->update(tower_yellow_path);
              myMap.setTile(gridPos.x, gridPos.y, MapTile::locked);
            } else if (TChecked && Checked4 == true){
              TowerType typeT = BLUE_MILK;
              Tower* tower = new Tower(typeT, winPos.x, winPos.y);
              towers.push_back(tower);
              tower->update(tower_blue_path);
              myMap.setTile(gridPos.x, gridPos.y, MapTile::locked);
            } else if (BChecked && Checked1 == true){
              BuildingType typeB = RADAR;
              Building* building= new Building(typeB, winPos.x, winPos.y);
              buildings.push_back(building);
              myMap.setTile(gridPos.x, gridPos.y, MapTile::locked);
            } else if (BChecked && Checked2 == true){
              BuildingType typeB = WEAPON;
              Building* building= new Building(typeB, winPos.x, winPos.y);
              buildings.push_back(building);
              myMap.setTile(gridPos.x, gridPos.y, MapTile::locked);
            } else if (BChecked && Checked3 == true){
              BuildingType typeB = STOCK;
              Building* building= new Building(typeB, winPos.x, winPos.y);
              buildings.push_back(building);
              myMap.setTile(gridPos.x, gridPos.y, MapTile::locked);
            }


          } else {
            printf("Zone not Buildable ! \n");
          }
        }
        break;

        default:
        break;
      }
    }

    Uint32 elapsedTime = SDL_GetTicks() - startTime;
    if (elapsedTime < FRAMERATE_MILLISECONDS) {
      SDL_Delay(FRAMERATE_MILLISECONDS - elapsedTime);
    }
  }

  /* Cleanup */
  SDL_DestroyWindow(window);
  SDL_Quit();
  for (Tower* tower : towers) {
    delete tower;
  }
  for (CatMonster* catMonster : catMonsters) {
    delete catMonster;
  }
  for (Building* building : buildings) {
    delete building;
  }

  return EXIT_SUCCESS;

}
