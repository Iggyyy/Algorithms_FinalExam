#include <bits/stdc++.h>
using namespace std;
vector<int> licznik, mianownik;

void readData()
{
    ifstream dane("dane_ulamki.txt");
    while(!dane.eof())
    {
        int a,b;
        dane>>a>>b;
        licznik.push_back(a);
        mianownik.push_back(b);
    }
    dane.close();
}

void zad1()
{
    int  maxL = 0, maxM = 0,minMian = 2e9;
    double maxV  = 0;
    for(int i =0;i<licznik.size(); i++)
    {
        double val = (double)licznik[i]/(double)mianownik[i];
        if(val > maxV)
        {
            maxV = val;
            maxL = licznik[i];
            maxM = mianownik[i];
            minMian = mianownik[i];
        }
        else if (val == maxV && minMian > mianownik[i])
        {
            maxV = val;
            maxL = licznik[i];
            maxM = mianownik[i];
            minMian = mianownik[i];
        }
    }
    cout<<"ZAD1:\n"<<maxL<<" "<<maxM<<endl;
}

int nwd(int a, int b)
{
    while(a != b)
    {
        if(a>b)
            a-=b;
        else
            b-=a;

    }
    return b;
}

void zad2()
{
    int counter = 0;
    for(int i =0; i < licznik.size(); i++)
    {
        if( nwd(licznik[i], mianownik[i]) == 1)
        {
            counter++;
            //cout<<licznik[i]<<" "<<mianownik[i]<<endl;
        }
    }
    cout<<"ZAD2:\n"<<counter<<endl;
}

void zad3()
{
    int suma = 0, sumaZ = 0;;
    for(int i =0; i<licznik.size(); i++)
    {
        sumaZ += licznik[i];
        int l = licznik[i], m = mianownik[i];
        int n = nwd(l,m);
        l/=n;
        m/=n;
        suma += l;
    }

    cout<<"ZAD3:\n"<<suma<<e ndl;
}

void zad4()
{
    int mian = 2*2*3*3*5*5*7*7*13, roz = 0;
    for(int i =0; i<licznik.size(); i++)
    {
        roz += licznik[i] * (mian / mianownik[i]);
    }
    cout<<"ZAD4:\n"<<roz<<" "<<endl;

}
int main()
{
    readData();
    zad1();
    zad2();
    zad3();
    zad4();
    //cout<<nwd(98, 120);

    return 0;
}
