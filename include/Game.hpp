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
    int m_nbWave;
    bool m_finished;
    bool m_doWave

    /*Creation des tableaux d'entité*/
    vector<CatMonster*> m_monsters;
    vector<Tower*> m_towers;
    vector<Building*> m_buildings;


    public:

    Game(); //constructeur

    //////GETTERS/////
    int getCagnotte();
    int getWave();
    bool getFinish();
    bool getDoWave();
    vector<CatMonster*> getVecCat();
    vector<Tower*> getVecTower();
    vector<Building*> getVecBuilding();

    //////SETTERS/////
    void setCagnotte(int money);
    void setWave(int vague);
    void setFinish(bool value);
    void setDoWave(bool value);
    // SET vecteurs monstres
    // SET vecteur tower
    // SET vecteur batiment

    //////OTHERS//////

    void startGame();
    void prepareWave(int numWave);
    bool canBuyTower(TowerType type);
    bool canBuyBuilding(BuildingType type);
    void construcTower(TowerType type, Position p);
    void construcBuilding(BuildingType type, Position p);
    void gameOver();

};

#endif
