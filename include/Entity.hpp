#ifndef DEF_ENFITY
#define DEF_ENTITY

#include <string>
#include <cmath>
#include "Case.hpp";

class Entity{
    protected:

      // Position position;
      float m_x;
      float m_y;
      string m_affichage;

    public:

    Entity();
    Entity(float x, float y);
     ~Entity();


//////////GETTERS/////////

      float getX();
      float getY();
      string getAffichage();

///////////SETTERS////////

      void setX(float X);
      void setY(float Y);
      void setAffichage(std::string path);

  //////////OTHERS/////////////

    float distance(float xA, float yA, float xB, float yB);
    virtual void afficher()=0;

    };

#endif
