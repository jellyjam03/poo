#include "Global.h"


void invert(char *a, int lg)
{
    int i;
    char aux;
    for (i=0; i<=lg/2; i++)
        {
         aux=*(a+i);
         *(a+i)=*(a+lg-1-i);
         *(a+lg-1-i)=aux;
        }
}

void copie(char *a, int &lga, const char *b, int lgb)
{
    int i;
    lga=lgb;
    for (i=0; i<lga; i++)
        *(a+i)=b[i];
    a[lgb]=0;
}
