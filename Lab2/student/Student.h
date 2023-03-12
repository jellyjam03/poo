class Student{

    char nume[30];
    int mat, ist, eng;

    public:

    bool setNume(const char *p);
    char* getNume();

    bool setMat(int x);
    int getMat();

    bool setIst(int x);
    int getIst();

    bool setEng(int x);
    int getEng();

    double avg();

};
