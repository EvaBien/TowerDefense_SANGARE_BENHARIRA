#ifndef DEF_GAME
#define DEF_GAME

#include "Tower.hpp"
#include "Building.hpp"
#include "CatMonster.hpp"
#include "Windows.hpp"
#include "Position.hpp"



class Game{
    private:
    // Attributs
    int m_cagnotte;
    int m_nbWave;
    bool m_finished;

    /*Creation des tableaux d'entités*/
    vector<CatMonster*> m_monsters;
    vector<Tower*> m_towers;
    vector<Building*> m_buildings;


    public:

    Game(); //constructeur

    //////GETTERS/////
    int getCagnotte();
    int getWave();
    bool getFinish();
    vector<CatMonster*> getVecCat();
    vector<Tower*> getVecTower();
    vector<Building*> getVecBuilding();

    //////SETTERS/////
    void setCagnotte(int money);
    void setWave(int vague);
    void setFinish(bool value);
    void setAddVecCat(CatMonster* cat);
    void setAddVecTower(Tower* tower);
    void setAddVecBuilding(Building* building);
    // void setDeleteVecCat(CatMonster* cat);
    // void setDeleteVecTower(Tower* tower);
    // void setDeleteVecBuilding(Building* building);

    //////OTHERS//////

    void startGame();
    void prepareWave(int numWave);
    bool canBuyTower(TowerType type);
    bool canBuyBuilding(BuildingType type);
    void construcTower(TowerType type, Position p);
    void construcBuilding(BuildingType type, Position p);
    void buildable(float x , float y , string typeBuild);
    void gameOver();

};

#endif
