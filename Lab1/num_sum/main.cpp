#include <iostream>
#include <cstdio>

using namespace std;

char s[30];
long long int sum, nr, i;

int main()
{
 FILE *input;
 input = fopen("./in.txt", "r");

 while (fscanf(input, "%s", s) != EOF)
       {
        nr=0;
        for (i=0; s[i]; i++)
            nr=nr*10+s[i]-'0';
        sum+=nr;
       }

 cout<<sum;
 return 0;
}
