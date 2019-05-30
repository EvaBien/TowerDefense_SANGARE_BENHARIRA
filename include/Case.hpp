#ifndef DEF_CASE
#define DEF_CASE

#include <string>
#include "Node.hpp"

enum ColorCase{
    OUT,
    IN,
    BUILD,
    PATH,
    NODE,
};


class Case{
    private:
    // Attributs
    float m_x; //jusqu'à quelle case peut tirer
    float m_y; //prix de la tour
    int m_side;
    bool m_buildable;
    ColorCase m_color;

    public:
    // Méthodes

    Case(float x, float y, ColorCase color);
    ~Case();

    /////GETTERS/////
    float getX();
    float getY();
    int getSide();
    bool getBuidable();

    /////SETTERS/////
    void setX(float x);
    void setY(float y);
    void setSide(float val);
    void setBuildable(bool val);

    //////OTHERS//////

    float distance(Case c);

    // bool idBuildable();

};

#endif
