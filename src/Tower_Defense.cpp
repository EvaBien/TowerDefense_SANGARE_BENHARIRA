// MAIN //
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "../include/Game.hpp"
#include "../include/Window.hpp"



int main(int argc, char **argv) {

  SDL_Window* window = init(); // Init fenêtre
  if (window == nullptr) {
    cout << "Error window init" << endl;
  }
  startGame();
}
