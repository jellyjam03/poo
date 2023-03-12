#include "Global.h"

int comparNume(Student a, Student b)
{
    char *nume1, *nume2;
    int i;
    nume1=a.getNume();
    nume2=b.getNume();
    for (i=0; *(nume1+i) && *(nume2+i); i++)
        if (*(nume1+i) < *(nume2+i)) return -1;
           else
           if (*(nume1+i) > *(nume2+i)) return 1;
    if (*(nume1+i)) return 1;
    if (*(nume2+i)) return -1;
    return 0;
}

int comparMat(Student a, Student b)
{
    int nota1, nota2;
    nota1=a.getMat();
    nota2=b.getMat();
    if (nota1 > nota2) return 1;
    if (nota2 > nota1) return -1;
    return 0;
}

int comparIst(Student a, Student b)
{
    int nota1, nota2;
    nota1=a.getIst();
    nota2=b.getIst();
    if (nota1 > nota2) return 1;
    if (nota2 > nota1) return -1;
    return 0;
}

int comparEng(Student a, Student b)
{
    int nota1, nota2;
    nota1=a.getEng();
    nota2=b.getEng();
    if (nota1 > nota2) return 1;
    if (nota2 > nota1) return -1;
    return 0;
}

int comparAvg(Student a, Student b)
{
    double avg1, avg2;
    avg1=a.avg();
    avg2=b.avg();
    if (avg1 > avg2) return 1;
    if (avg2 > avg1) return -1;
    return 0;
}
