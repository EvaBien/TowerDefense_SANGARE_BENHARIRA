#ifndef DEF_TOWER
#define DEF_TOWER

#include <string>
#include "Entity.hpp"
#include "Tower.hpp"


enum BuildingType{
    RADAR,
    WEAPON,
    STOCK,
};

class Building{
    private:
    // Attributs
    Case *m_case;
    int m_portee; //jusqu'à quelle case peut tirer
    int m_price; //prix de la tour
    BuildingType type; //type de tour en fonction couleur

    public:
    // Méthodes

    Building(BuildingType type, Case &case); //constructeur

    /////GETTERS/////
    Case getCase();
    int getGain();
    int getPortee();
    int getPrice();
    int getBuildingType();


    /////SETTERS/////
    void setCase(Case &case);
    void setGain(int newGain);
    void setPortee(int portee);
    void setPrice(int price);
    void setBuildingType(BuildingType type);

    //////OTHERS//////


    void afficher();
    void upgradeTower(Tower t);

};

#endif
