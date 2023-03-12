#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

struct cuvant
{
    char cuv[256];
    int lg;
}v[100];

char prop[256], *p;
int nrcuv, i;

void bbsort (cuvant v[100]);
bool ok (cuvant a, cuvant b);

int main()
{
 scanf("%[^\n]", prop);
 p=strtok(prop, " ");
 while (p)
       {
        strcpy(v[nrcuv].cuv, p);
        v[nrcuv].lg=strlen(v[nrcuv++].cuv);
        p=strtok(NULL, " ");
       }
 bbsort(v);
 for (i=0; i<nrcuv; i++)
     cout<<v[i].cuv<<'\n';
 return 0;
}

void bbsort(cuvant v[])
{
 cuvant aux;
 bool gasit=0;
 int i;

 do
 {
     gasit=0;
     for (i=0; i<nrcuv-1; i++)
         if (!ok(v[i], v[i+1]))
            {
             gasit=1;
             aux=v[i];
             v[i]=v[i+1];
             v[i+1]=aux;
            }
 }
 while (gasit);

}

bool ok (cuvant a, cuvant b)
{
    return ((a.lg > b.lg) || (a.lg == b.lg && strcmp(a.cuv, b.cuv) > 0));
}
