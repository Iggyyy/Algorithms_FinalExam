#include <bits/stdc++.h>
using namespace std;

void wydluzKlucz(string &klucz, int len)
{
    string nowy = klucz;
    int counter = 0;
    while(nowy.length() < len)
    {
        nowy+= klucz;
        counter++;
    }
    cout<<"powtorzen: "<<counter<<endl;
    klucz = nowy;
}


string zaszyfruj(string haslo, string klucz)
{
    string nowy = "";
    for(int i =0; i<haslo.size(); i++)
    {
        int k = ('A' - klucz[i])*-1 ;

        cout<<haslo[i] + k<<endl;
        if(haslo[i]+k > 'Z')
        {
            nowy+= 'A' + k - ('Z' - haslo[i] + 1);
        }
        else
            nowy += haslo[i]+k;

    }

    return nowy;
}

void zad1()
{
    ifstream plik("dokad.txt");
    string haslo;
    string klucz = "LUBIMYCZYTAC";
    getline(plik,haslo);
    wydluzKlucz(klucz, haslo.length());

    cout<<zaszyfruj( haslo,klucz);


    //cout<<haslo<<endl<<klucz<<endl;

    plik.close();
}

int main()
{
    zad1();
    return 0;
}
