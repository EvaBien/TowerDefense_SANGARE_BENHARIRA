#ifndef DEF_PERSONNAGE
#define DEF_PERSONNAGE

#include <string>

class Tower{
    private:
    // Attributs
    int m_damages; //nb point de dégat
    int m_portee; //jusqu'à quelle case peut tirer
    int m_cadence; //vitesse à laquelle tour peut tirer
    int m_price; //prix de la tour
    TowerType type; //type de tour en fonction couleur

    public:
    // Méthodes

    Tower(); //constructeur

    int getDamages();
    int getPortee();
    int getCadence();
    int getPrice();

    void setDamages(int newDamages);
    void setPortee(int portee);
    void setCadence(int cadence);
    void setPrice(int price);

    //void Damaged(int nbDamages){} à voir si on a besoin de cette fonction


    bool isBuildable(){

    }

    //BESOIN FONCTION POUR CHOIX CIBLE DU TIR

    //void destroy(){}   à voir si on a besoin de cette fonction

};

#endif