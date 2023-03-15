#include "Sort.h"

Sort::Sort(int nr, int minim, int maxim){

    if (minim > maxim) return;
    if (nr<=0) return;

    n=nr;
    a=new int[n];
    srand(time(NULL));
    int i;
    for (i=0; i<n; i++)
        a[i]=rand()%(maxim-minim+1)+minim;

}

Sort::Sort() : n(10), a(new int[n]){

    int i;
    for (i=0; i<n; i++)
        a[i]=n-i;

}

Sort::Sort(int v[], int nr){

    if(nr <= 0) return;
    a=new int[nr];
    n=nr;
    int i;
    for (i=0; i<n; i++)
        a[i]=v[i];

}

Sort::Sort(int nr, ...){

    if (nr <= 0) return;

    int i;
    n=nr;
    a=new int[n];

    va_list l;
    va_start(l, nr);

    for (i=0; i<n; i++)
        a[i]=va_arg(l, int);
    va_end(l);

}

Sort::Sort(char s[]){

    char *p;
    int nr=0, i, j;
    for (i=0; s[i]; i++)
        if (s[i]==',')
           nr++;
    n=nr+1;
    a=new int[n];

    i=0;
    p=strtok(s, ",");
    while (p)
          {
           nr=0;
           for (j=0; p[j]; j++)
               nr=nr*10+p[j]-'0';
           a[i++]=nr;
           p=strtok(NULL, " ");
          }

}
    // add constuctors

void Sort::InsertSort(bool ascendent){

    int i, j, aux;
    for (i=0; i<n-1; i++)
        for (j=i+1; j>0; j--)
            if (a[j] < a[j-1])
               {
                aux=a[j];
                a[j]=a[j-1];
                a[j-1]=aux;
               }
               else
               break;
    if (ascendent == false) this->rev();

}

void Sort::QuickSort(bool ascendent){

    struct interval{
        int st, dr;
    }S[n];

    ///de ce nu merge?
    //interval *S = new inetrval[n];
    int vf=1, p, aux, pivot, st, dr;
    S[vf].st=0; S[vf].dr=n-1;
    srand(time(NULL));

    while (vf)
          {
           if (S[vf].dr-S[vf].st < 1) vf--;
              else
              {
                  p=rand()%(S[vf].dr-S[vf].st+1)+S[vf].st;
                  pivot=a[p];
                  aux=a[S[vf].st]; a[S[vf].st]=a[p]; a[p]=aux;
                  st=S[vf].st; dr=S[vf].dr;
                  while (S[vf].st < S[vf].dr)
                        {
                         while (S[vf].st < S[vf].dr && pivot <= a[S[vf].dr]) S[vf].dr--;
                         a[S[vf].st]=a[S[vf].dr];
                         while (S[vf].st < S[vf].dr && pivot >= a[S[vf].st]) S[vf].st++;
                         a[S[vf].dr]=a[S[vf].st];
                        }
                  a[S[vf].st]=pivot;
                  p=S[vf].st;
                  vf--;
                  S[++vf].st=st; S[vf].dr=p-1;
                  S[++vf].st=p+1; S[vf].dr=dr;
                  this->Print();
              }
          }
    if (ascendent == false) this->rev();
    //delete[] S;
}

void Sort::BubbleSort(bool ascendent){

    int i, aux;
    bool gasit;

    do
    {
     gasit=0;
     for (i=0; i<n-1; i++)
         if (a[i] > a[i+1])
            {
             gasit=1;
             aux=a[i];
             a[i]=a[i+1];
             a[i+1]=aux;
            }
    }
    while (gasit);

    if (ascendent == false) this->rev();
}

void Sort::Print(){

    int i;
    for (i=0; i<n; i++)
        std::cout<<a[i]<<' ';
    std::cout<<'\n';

}

int Sort::GetElementsCount(){

    return n;

}

int Sort::GetElementFromIndex(int index){

    return a[index];

}

void Sort::rev(){

    int i, aux;
    for (i=0; i<n/2; i++)
        {
         aux=a[i];
         a[i]=a[n-1-i];
         a[n-1-i]=aux;
        }

}
