#ifndef DEF_GAME
#define DEF_GAME

#include <string>
#include "Tower.hpp"
#include "Building.hpp"




class Game{
    private:
    // Attributs
    int m_cagnotte;
    int m_nbVague;
    bool m_finished;
    // Attribut vecteurs monstres
    // Attribut vecteur tower
    // Attribut vecteur batiment

    public:

    Game(); //constructeur

    //////GETTERS/////
    int getCagnotte();
    int getVague();
    //GET vecteurs monstres
    //GET vecteur tower
    //GET vecteur batiment

    //////SETTERS/////
    void setCagnotte(int money);
    void setVague(int vague);
    // SET vecteurs monstres
    // SET vecteur tower
    // SET vecteur batiment

    //////OTHERS//////

    void startGame();
    void lancerVague(int numVague);
    bool canBuyTower(TowerType type);
    bool canBuyBuilding(BuildingType type);
    void construcTower(TowerType type, Position p);
    void construcBuilding(BuildingType type, Position p);
    void gameOver();

};

#endif
