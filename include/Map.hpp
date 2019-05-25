#ifndef DEF_MAP
#define DEF_MAP




class Map{
    private:
    // Attributs
    int m_height;
    int m_width;

    public:

    Map(); //constructeur

    //////GETTERS/////
    int getHeight();
    int getWidth();

    //////SETTERS/////
    int setHeight();
    int setWidth();

    //////OTHERS//////
    void Map::Scale(int heightPPM, int widthPPM); //créer carte de la taille souhaitée en fonction du plan fourni en ppm (échelle *30)
    void readPPM(); //lis le fichier ppm et y récupère les info qui nous permettrons de construire la carte et ses différnets éléments.  

    //void readITD(); ? à mettre ici ?

};

#endif