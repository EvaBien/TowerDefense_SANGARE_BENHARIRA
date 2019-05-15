#ifndef DEF_CATMONSTER
#define DEF_CATMONSTER

#include <string>

class CatMonster{
    private:
    // Attributs
    int m_life; //nb point de vie
    int m_gainDeath; //nb piece reçu par joueur qd monstre meurt
    int m_speed; //vitesse à laquelle monstre se déplace
    CatMonsterType type; //type de chat mutant

    public:
    // Méthodes

    CatMonster(); //constructeur

    //////GETTERS/////
    int getLife();
    int getGainDeath();
    int getSpeed();

    //////SETTERS/////
    void setLife(int newLife);
    void setGainDeath(int gain);
    void setSpeed(int speed);

    //////OTHERS//////
    void beDamaged(int nbDamages);

    void move();

    bool isAlive();

    void destroy();
};

#endif