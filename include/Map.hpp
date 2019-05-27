#ifndef DEF_MAP
#define DEF_MAP
#include "Case.hpp"



class Map{
    private:
    // Attributs
    int m_height;
    int m_width;
    Case m_CaseMap[m_height*m_width];

    public:

    Map(); //constructeur
    ~Map();

    //////GETTERS/////
    int getHeight();
    int getWidth();
    Case getCase(int position);
    Case *getAllCases();

    //////SETTERS/////
    void setHeight();
    void setWidth();
    void setCaseMap(int Position, Case *c);


    //////OTHERS//////

    int calculCoordX(int position);
    int calculCoordY(int position);  
    int calculPosition(float x, float y); // Calcul la position de la case dans le tableau en fonction des coordonnées du pixel
    void Scale( int heightPPM, int widthPPM); //créer carte de la taille souhaitée en fonction du plan fourni en ppm (échelle *30)
    void readPPM(); //lis le fichier ppm et y récupère les info qui nous permettrons de construire la carte et ses différnets éléments.
    void drawMap();

    //void readITD(); ? à mettre ici ?

};

#endif
