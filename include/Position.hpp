#ifndef DEF_POSITION
#define DEF_POSITION

#include <string>
#include <cmath>

class Position{
    protected:

      float m_X;
      float m_Y;

    public:

    Position(float X,float Y); //constructeur
    ~Position();


//////////GETTERS/////////

      float getX();
      float getY();

///////////SETTERS////////

      void setX(float X);
      void setY(float Y);
      void setPosition(float X, float Y);
  //////////OTHERS/////////////

      float distance(Position p);

    };

#endif
