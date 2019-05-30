#ifndef DEF_MAP
#define DEF_MAP
#include "Case.hpp"



class Map{
    private:
    // Attributs
    int m_height;
    int m_width;
    Case m_CaseMap[];

    public:

    Map(); //constructeur
    ~Map();

    //////GETTERS/////
    int getHeight();
    int getWidth();
    Case getCase(int position);
    Case *getAllCases();
    int getSizeCases();

    //////SETTERS/////
    void setHeight();
    void setWidth();
    void setCaseMap(int Position, Case *c);
    void setAllCases(Case *tab);
    void setParams(int height, int width);


    //////OTHERS//////

    int calculCoordX(int position);
    int calculCoordY(int position);
    int calculPosition(float x, float y); // Calcul la position de la case dans le tableau en fonction des coordonnées du pixel
    void Scale( int heightPPM, int widthPPM); //créer carte de la taille souhaitée en fonction du plan fourni en ppm (échelle *100)
    void readPPM(char* filename);
    void initMap();
    ColorCase verifColor(int r, int v, int b);
};

#endif
