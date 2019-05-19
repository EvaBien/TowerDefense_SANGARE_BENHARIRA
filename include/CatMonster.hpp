#ifndef DEF_CATMONSTER
#define DEF_CATMONSTER

#include <string>
#include "Entity.hpp"


enum CatMonsterType{
    KITTEN,
    FATCAT,
    JUSTCAT,
};


class CatMonster : public Entity{
    private:
    // Attributs
    int m_life; //nb point de vie
    int m_gainDeath; //nb piece reçu par joueur qd monstre meurt
    int m_speed; //vitesse à laquelle monstre se déplace
    CatMonsterType type; //type de chat mutant
    string m_affichage;

    public:

    CatMonster(CatMonsterType type); //constructeur
    ~CatMonster(); // Desctructeur

    //////GETTERS/////
    int getLife();
    int getGainDeath();
    int getSpeed();
    int getType();
    string getAffichage();

    //////SETTERS/////
    void setLife(int newLife);
    void setGainDeath(int gain);
    void setSpeed(int speed);
    void setAffichage(string path);


    //////OTHERS//////

    void afficher();
    void beDamaged(int nbDamages);
    void move();
    bool isAlive();    string m_affichage;

    void destroy();


};

#endif
