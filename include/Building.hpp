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
    int m_portee; //jusqu'à quelle case peut tirer
    int m_price; //prix de la tour
    BuildingType type; //type de tour en fonction couleur
    string m_affichage;

    public:
    // Méthodes

    Building(BuildingType type, Position p); //constructeur

    /////GETTERS/////
    int getGain();
    int getPortee();
    int getPrice();
    int getBuildingType();
    string getAffichage();


    /////SETTERS/////
    void setGain(int newGain);
    void setPortee(int portee);
    void setPrice(int price);
    void setBuildingType(BuildingType type);
    void setAffichage(string path);

    //////OTHERS//////


    void afficher();
    bool isBuildable(Position p);
    void upgradeTower(Tower t);

};

#endif
