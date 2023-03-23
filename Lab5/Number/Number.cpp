#include "Number.h"

using namespace std;

Number::Number(const char * value, int base)
{
    int i;
    if (!(2 <= base && base <= 16)) return;
    for (i = 0; value[i]; i++)
        if (!(('0' <= value[i] && value[i] <= '9') || ('A' <= value[i] && value[i] <= 'F'))) return;
           else
           if ('0' <= value[i] && value[i] <= '9' && value[i]-'0' >= base) return;
              else
               if ('A' <= value[i] && value[i] <= 'F' && value[i]-'A'+10 >= base) return;

    baza = base;
    lg = i;
    v = new char[lg+1];
    for (i=0; i<lg; i++)
        v[i]=value[lg-1-i];
    v[lg]=0;
}

Number::~Number()
{
    delete[] v;
}

void Number::Print()
{
    int i;
    for (i=lg-1; i>=0; i--) cout<<v[i];
    cout<<'\n';
}

Number::Number(const Number& x)///copy constructor
{
    baza=x.baza;
    lg=x.lg;
    ///delete[] v;
    v=new char[lg+1];
    memcpy(v, x.v, lg+1);
}

Number::Number(Number&& x)///move constructor
{
    lg=x.lg; x.lg=0;
    baza=x.baza; x.baza=0;
    v=x.v; x.v=nullptr;
}

void Number::SwitchBase(int newBase)
{
    if (!(2 <= newBase && newBase <= 16)) return;

    if (baza == newBase) return;

    int lgmax, aux, i, j;

    if (baza == 10)
       {
        ///noul numar va avea maxim 4*lg cifre (cazul in care numarul pe care il convertim are toate cifrele 9, iar noua baza este 2
        int v2[4*lg+1];///declar un vector auxiliar in care imi voi construi inversul numarului

        ///transform sirul de caractere v intr-un numar intreg (in b10)
        aux=0;
        for (i=lg-1; i>=0; i--) aux=aux*10+v[i]-'0';

        i=0;
        while (aux)///il convertesc in baza ceruta
        {
            v2[i++]=aux%newBase;
            aux/=newBase;
        }

        ///memorez inversul sirului in this->v cu precizarea ca transform cifrele in caractere
        ///de asemenea, v2 poate avea dimensiunea mai mare decat v asa ca trebuie alocata memorie
        delete[] v;
        v = new char [i+1]; ///i a ramas egal cu numarul de cifre al noului numar

        for (j=0; j<i; j++)
            if (v2[j] >= 10)
               v[j]='A'+v2[j]-10;
               else
               v[j]='0'+v2[j];

        ///updatez si restul campurilor
        lg=i;
        baza=newBase;
        v[i]=0;
       }
    else
    if (newBase == 10)
       {
        ///calculam numarul maxim posibil de cifre al noului numar
        ///cel mai mare caz e atunci cand schimbam din baza 16 in baza 10 si avem F peste tot
        ///vom avea 15*(1+10+100+..+10^(lg-1))
        ///asadar, vom avea maxim lg+1 cifre in noul numar
        ///de asemenea, ne bazam pe faptul ca numerele sunt < 2^31

        int aux=0, cif, pbaz=1;
        for (i=0, aux=0; i<lg; i++)
            {
                if (v[i] >= 'A' && v[i] <= 'F') cif=10+v[i]-'A';
                   else cif=v[i]-'0';
                aux=aux+pbaz*cif;
                pbaz*=baza;
            }
        char v2[lg+2];
        i=0;
        while (aux)
        {
            v2[i++]=aux%10+'0';
            aux/=10;
        }

        ///exista posibilitatea sa ocup mai multa memorie
        delete[] v;
        v = new char[i+1];

        for (j=0; j<i; j++)
            v[j]=v2[j];

        lg=i;
        baza=10;
        v[lg]=0;
       }
       else
       {
           this->SwitchBase(10);
           this->SwitchBase(newBase);
       }
}

Number& operator- (const Number& a, const Number& b)
{
    ///de ce nu merge? ce ar trebui sa returnez?
    ///if (a < b) return a; ///nu se face scaderea

    Number x(a), y(b);

    int baza_finala=max(x.GetBase(), y.GetBase());

    x.SwitchBase(10);
    y.SwitchBase(10);

    ///il scad pe y din x

    char *rez = new char[x.GetDigitsCount() + 1];
    int t=0, i, j;
    bool imprumut;
    char aux;

    for (i=0; i<y.lg; i++)
    {
        imprumut=0;
        t = t + x.v[i]-'0' - (y.v[i] - '0');
        if (t < 0) {t+=10; imprumut=1;}
        rez[i]=t%10 + '0';
        t/=10;
        if (imprumut) t--;
    }
    for (; i<x.lg; i++)
    {
        imprumut=0;
        t = t + x.v[i]-'0';
        if (t < 0) {t+=10; imprumut=1;}
        rez[i]=t%10 + '0';
        t/=10;
        if (imprumut) t--;
    }
    rez[i]=0;

    for (j=0; j<i/2; j++)
    {
        aux=rez[j];
        rez[j]=rez[i-1-j];
        rez[i-1-j]=aux;
    }

    Number *temp = new Number(rez, 10);
    temp->SwitchBase(baza_finala);

    return *temp;

}

int  Number::GetDigitsCount()
{
    return lg;
}

int  Number::GetBase()
{
    return baza;
}

Number& operator+ (const Number& a, const Number& b)
{
    Number x(a), y(b);

    int baza_finala=max(x.GetBase(), y.GetBase());

    y.SwitchBase(10);
    x.SwitchBase(10);

    char *rez = new char[max(x.GetDigitsCount(), y.GetDigitsCount())+2];

    int t=0, i, j;
    char aux;

    for (i=0; i<x.lg && i<y.lg; i++)
    {
        t = t + (x.v[i]-'0' + y.v[i]-'0');
        rez[i] = t % 10 + '0';
        t = t/10;
    }

    for (; i<x.lg; i++)
    {
        t = t + x.v[i]-'0';
        rez[i] = t%10 + '0';
        t = t/10;
    }

    for (; i<y.lg; i++)
    {
        t = t + y.v[i]-'0';
        rez[i] = t%10 + '0';
        t = t/10;
    }

    if (t) rez[i++] = t + '0';

    rez[i]=0;

    for (j=0; j<i/2; j++)
    {
        aux = rez[j];
        rez[j] = rez[i-1-j];
        rez[i-1-j] = aux;
    }

    Number* temp = new Number(rez, 10);
    temp->SwitchBase(baza_finala);

    delete[] rez;

    return *temp;

}

bool operator> (const Number& a, const Number& b)
{
    Number x(a), y(b);
    x.SwitchBase(10);
    y.SwitchBase(10);

    int i;
    for (i=0; i<x.lg && i<y.lg; i++)
        if (x.v[i] > y.v[i]) return 1;
           else
           if (x.v[i] < y.v[i]) return 0;

    return x.lg > y.lg;
}

bool operator>= (const Number& a, const Number& b)
{
    Number x(a), y(b);
    x.SwitchBase(10);
    y.SwitchBase(10);

    int i;
    for (i=0; i<x.lg && i<y.lg; i++)
        if (x.v[i] > y.v[i]) return 1;
           else
           if (x.v[i] < y.v[i]) return 0;

    return x.lg >= y.lg;
}

bool operator< (const Number& a, const Number& b)
{
    return !(a >= b);
}

bool operator<= (const Number& a, const Number& b)
{
    return !(a > b);
}

bool operator== (const Number& a, const Number& b)
{
    Number x(a), y(b);
    x.SwitchBase(10);
    y.SwitchBase(10);

    if (x.lg != y.lg) return 0;

    int i;
    for (i=0; i<x.lg; i++)
        if (x.v[i] != y.v[i]) return 0;
    return 1;
}

bool operator!= (const Number& a, const Number& b)
{
    return !(a == b);
}

Number& Number::operator= (const Number& a)
{
    baza=a.baza;
    lg=a.lg;

    delete[] v;
    v = new char[a.lg+1];

    int i;
    for (i=0; i<lg; i++)
        v[i] = a.v[i];
    v[i]=0;

    return *this;
}

char Number::operator[] (int poz)
{
    return *(v+lg-1-poz);
}

Number& operator+= (Number& a, const Number& b)
{
    return a = a + b;
}

Number& operator-= (Number& a, const Number& b)
{
    return a = a - b;
}

Number& Number::operator-- ()///prefixat
{
    Number a(*this);
    delete[] v;
    v = new char[lg];
    lg--;
    int i;
    for (i=0; i<lg; i++)
        v[i]=a.v[i];
    v[lg]=0;

    return *this;
}

Number& Number::operator-- (int val)
{
    Number a(*this);
    delete[] v;
    v = new char[lg];
    lg--;
    int i;
    for (i=0; i<lg; i++)
        v[i]=a.v[i+1];
    v[lg]=0;

    return *this;

}

Number& Number::operator= (const int x)
{
    int aux, i, lgx=0;
    aux=x;

    while (aux) {aux/=10; lgx++;}

    char s[lgx+1];

    for (i=0, aux=x; i<lgx; i++, aux/=10)
        s[i]=aux%10+'0';

    s[lgx]=0;
    Number b(s, 10);
    b.SwitchBase(baza);

    lg=b.GetDigitsCount();

    delete[] v;
    v = new char[lg+1];

    for (i=0; i<lg; i++)
        v[i]=b.v[i];

    return *this;
}

Number::Number(const int x)
{
    int aux, i;
    aux=x;

    baza=10;
    lg=0;

    while (aux) {aux/=10; lg++;}

    v = new char[lg+1];

    for (i=0, aux=x; i<lg; i++, aux/=10)
        v[i]=aux%10+'0';
}

Number& Number::operator= (const char* const p)
{
    int i;

    for (i=0; p[i]; i++);
    lg=i;

    delete[] v;
    v = new char[lg+1];

    for (i=0; i<lg; i++)
        v[i]=p[lg-1-i];
    v[lg]=0;

    return *this;
}
