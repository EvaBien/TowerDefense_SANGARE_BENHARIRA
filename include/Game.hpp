#ifndef DEF_GAME
#define DEF_GAME

#include <string>
#include "Tower.hpp"
#include "Building.hpp"
#include "CatMonster.hpp"
#include "Windows.hpp"



class Game{
    private:
    // Attributs
    int m_cagnotte;
    int m_nbVague;
    bool m_finished;

    /*Creation des tableaux d'entité*/
    // Add entité dans tableau --> tab.push_back(entity)
    vector<CatMonster*> m_monsters;
    vector<Tower*> m_towers;
    vector<Building*> m_buildings;


    public:

    Game(); //constructeur

    //////GETTERS/////
    int getCagnotte();
    int getVague();
    vector<CatMonster*> getVecCat();
    vector<Tower*> getVecTower();
    vector<Building*> getVecBuilding();

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
