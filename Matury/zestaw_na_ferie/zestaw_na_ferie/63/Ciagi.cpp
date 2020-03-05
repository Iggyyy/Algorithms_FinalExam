#include <bits/stdc++.h>
using namespace std;
vector<string> dane;
ofstream wyniki("wyniki.txt");

bool czyDwucykl(string wyraz)
{
    if(wyraz.length() %2 == 1)
        return false;

   int m = wyraz.length() / 2;

   string fir = wyraz.substr(0, m);
   string sec = wyraz.substr(m, m);

    if(fir == sec)
        return true;
    else return false;
}

void zad1()
{
    wyniki<<"63.1\n";
    for(int i =0; i<dane.size(); i++)
    {
        if(czyDwucykl(dane[i]) == true)
            wyniki<<dane[i]<<endl;
    }
    wyniki<<endl;

}

void zad2()
{
    int licznik = 0;

    for(int i =0; i<dane.size(); i++)
    {
        string wyraz = dane[i];
        char poprzedni = 'x';
        bool jest = true;

        for(int j =0; j<wyraz.size(); j++)
        {
            if( (char)wyraz[j] == (char)poprzedni && (char)poprzedni == '1')
                jest = false;
            poprzedni = (char)wyraz[j];
        }
        if(jest == true)
            licznik++;


    }
    wyniki<<"63.2\nIle: "<<licznik<<endl<<endl;


}

void sitoEra(vector<int> &tab, int n)
{
    tab[0] = tab[1] = 0;
    for(int i = 2; i*i<=n; i++)
    {
        if(tab[i] == 0)
            for(int j = i*i; j<=n; j+=i)
                tab[j] = 1;
    }

}

void zad3()
{
    int najw = 0, najm = 2e9, licznik = 0;
    vector<int> sito(pow(2,20), 0);

    for(int i =0; i< dane.size(); i++)
    {
        int x = stoi(dane[i], nullptr, 2);
        int pierwszych = 0 ,dzielnikow = 0;
        int pom = x, d = 2;
        cout<<endl<<x<<" d: ";
        while(pom>1)
        {
            if(pom % d == 0)
            {
                pom/=d;
                if(sito[d] == 0)
                    pierwszych++;
                dzielnikow++;
                cout<<d<<" ";
            }
            else d++;
        }


        if(pierwszych == dzielnikow && pierwszych ==2)
        {
            if(x > najw)
                najw = x;
            if (x < najm)
                najm = x;
            licznik++;
        }

    }


    wyniki<<"63.3 \nIle ciagow: "<<licznik<<"\nNajwieksza: "<<najw<<"\nNajmniejsza: "<<najm<<endl;
}

int main()
{
    ifstream plik("ciagi.txt");
    while(!plik.eof())
    {
        string s; plik >> s;
        dane.push_back(s);
    }


    zad1();
    cout<<"utworzono 1"<<endl;
    zad2();
    cout<<"utworzono 2"<<endl;
    zad3();
    cout<<"utworzono 3"<<endl;

    wyniki.close();
    plik.close();
}
