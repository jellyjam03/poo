#include "Math.h"


static int Add(int a, int b)
{
    return a+b;
}

static int Add(int a, int b, int c)
{
    return a+b+c;
}

static int Add(double a, double b)///nu ar trebui return type-ul sa fie double?
{
    return a+b;
}

static int Add(double a, double b, double c)
{
    return a+b+c;
}

static int Mul(int a, int b)
{
    return a*b;
}

static int Mul(int a, int b, int c)
{
    return a*b*c;
}

static int Mul(double a, double b)
{
    return a*b;
}

static int Mul(double a, double b, double c)
{
    return a*b*c;
}

static int Add(int counter,...) // sums up a list of integers
{
    va_list p;
    va_start(p, counter);

    int i, sum;

    for (i=0, sum=0; i<counter; i++)
        sum+=va_arg(p, int);

    va_end(p);
    return sum;
}

static char* Add(const char *a, const char *b)
{
    int lg1, lg2, lg3, i, carry, tmp;
    char aux;

    for (lg1=0; *(a+lg1); lg1++);
    for (lg2=0; *(b+lg2); lg2++);

    char *s1 = new char[lg1];
    char *s2 = new char[lg2];
    char *s3 = new char[std::max(lg2, lg1)+1];

    copie(s1, lg1, a, lg1);
    copie(s2, lg2, b, lg2);
    invert(s1, lg1);
    invert(s2, lg2);

    for (i=0, carry=0; i<lg1 && i<lg2; i++)
        {
         carry=carry+s1[i]-'0'+s2[i]-'0';
         s3[i]='0'+carry%10;
         carry/=10;
        }
    lg3=i;
    while (lg3 < lg1)
          {
           carry=carry+s1[lg3]-'0';
           s3[lg3]='0'+carry%10;
           carry/=10;
           lg3++;
          }
    while (lg3 < lg2)
          {
           carry=carry+s2[lg3]-'0';
           s3[lg3]='0'+carry%10;
           carry/=10;
           lg3++;
          }
    s3[lg3]=0;
    invert(s3, lg3);
    delete[] s1;
    delete[] s2;
    return s3;
}

