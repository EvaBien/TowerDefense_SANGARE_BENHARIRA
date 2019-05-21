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


/*
PROBLEME :

- Quand on tue un monstre on veut qu'il sorte du vecteur et qu'il
donne de l'argent à la m_cagnotte
- La cagnotte et le vecteur sont des attributs de Game
- Game inclus CatMonster

--> CatMonster ne peut pas accéder à Game, alors comment agir
sur le vecteur et sur la cagnotte ?

===> Proposition : Inclure un attribut "pointeur game" dans Monster,
pour savoir à quel "jeu" le monstre appartient (même s'il n'y en a qu'un à la fois)

=> On pourra ainsi accéder à son vecteur pour le supprimer et à la cagnotte quand il meurt

==> ajouter entity.hpp
read ITD à faire


*/
