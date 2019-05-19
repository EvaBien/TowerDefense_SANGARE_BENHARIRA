#ifndef DEF_ENFITY
#define DEF_ENTITY

#include <string>
#include "Position.hpp"

class Entity{
    protected:

      Position position;
      string m_affichage;

    public:

    Entity(Position position,string path); //constructeur
     ~Entity();


//////////GETTERS/////////

      Position getPosition()
      string getAffichage();

///////////SETTERS////////

      void setPosition(Position p;)
      void setAffichage(std::string path);

  //////////OTHERS/////////////

    virtual void afficher()=0;

    };

#endif
