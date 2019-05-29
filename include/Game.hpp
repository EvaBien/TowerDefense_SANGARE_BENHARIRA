#ifndef DEF_GAME
#define DEF_GAME

#include "Tower.hpp"
#include "Building.hpp"
#include "CatMonster.hpp"
#include "Windows.hpp"
#include "Map.hpp"


class Game{
    private:
    // Attributs
    int m_cagnotte;
    int m_nbWave;
    bool m_finished;
    Map m_map;

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
    Map getMap();
    vector<CatMonster*> getVecCat();
    vector<Tower*> getVecTower();
    vector<Building*> getVecBuilding();

    //////SETTERS/////
    void setCagnotte(int money);
    void setWave(int vague);
    void setFinish(bool value);
    void setMap(Map map);
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
    void construcTower(TowerType type, Case c);
    void construcBuilding(BuildingType type, Case c);
    void buildable(float x , float y , string typeBuild);
    void gameOver();

};

#endif
