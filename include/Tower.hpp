#ifndef DEF_TOWER
#define DEF_TOWER

#include <string>
#include "Entity.hpp"
#include "CatMonster.hpp"


enum TowerType{
    RED_LASER,
    GREEN_GRASS,
    YELLOW_GAMMELLE,
    BLUE_MILK,
};

class Tower{
    private:
    // Attributs
    Case *m_case;
    int m_damages; //nb point de dégat
    int m_portee; //jusqu'à quelle case peut tirer
    int m_cadence; //vitesse à laquelle tour peut tirer
    int m_price; //prix de la tour
    TowerType type; //type de tour en fonction couleur
    CatMonster *target;
    Game *game;

    public:
    // Méthodes

    Tower(TowerType type, Case &case); //constructeur

    /////GETTERS/////
    Case getCase();
    int getDamages();
    int getPortee();
    int getCadence();
    int getPrice();
    int getTowerType();
    int getGame();


    /////SETTERS/////
    void setCase(Case &case);
    void setDamages(int newDamages);
    void setPortee(int portee);
    void setCadence(int cadence);
    void setPrice(int price);
    void setTowerType(TowerType type);
    void setGame(Game *game);


    //////OTHERS//////

    void afficher();
    void attack();

};

#endif
