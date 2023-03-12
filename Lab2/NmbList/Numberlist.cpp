#include "Numberlist.h"


void NumberList :: Init(){

    counter=0;

}

bool NumberList :: Add(int x){

    if (counter + 1 >= 10) return 0;

    numbers[counter++]=x;
    return 1;

}

void NumberList :: Print(){

    int i;
    for (i=0; i<counter; i++)
        std::cout<<numbers[i]<<'\n';

}

void NumberList :: Sort(){

    bool gasit;
    int aux, i;

    do
    {
        gasit=0;
        for (i=0; i<counter-1; i++)
            if (numbers[i] > numbers[i+1])
               {
                gasit=1;
                aux=numbers[i];
                numbers[i]=numbers[i+1];
                numbers[i+1]=aux;
               }
    }
    while (gasit);

}
