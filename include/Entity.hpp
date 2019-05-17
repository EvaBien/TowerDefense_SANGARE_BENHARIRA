#ifndef DEF_ENFITY
#define DEF_ENTITY

#include <string>

class Entity{
    protected:

      float m_X;
      float m_Y;
      string m_affichage;

    public:

    Entity(float X,float Y,string path); //constructeur


//////////GETTERS/////////

      float getX();
      float getY();
      string getAffichage();

///////////SETTERS////////

      void setX(float X);
      void setY(float Y);
      void setAffichage(std::string path);

  //////////OTHERS/////////////

    virtual void afficher()=0;

    };

#endif
