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
    void readPPM();
    //void readITD(); ? à mettre ici ?

};

#endif