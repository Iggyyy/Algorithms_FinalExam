#include <bits/stdc++.h>

using namespace std;
vector<int> liczby;
ofstream wyniki("wyniki4.txt");

void zad1()
{
    vector<int> sito(5001, 0);
    sito[0] = 1;
    sito[1] = 1;

    for(int i =2; i*i<=5000; i++)
    {
        if(sito[i] == 0)
        {
            for(int j = i*i; j<=5000; j+=i)
            {
                sito[j] = 1;
            }
        }
    }

    for(int i =0; i<liczby.size(); i++)
     {
         if(liczby[i] < 5001 && liczby[i] >= 100 && sito[liczby[i]] == 0)
            wyniki<<liczby[i]<<" ";
     }

    cout<<"zapisano 4.1"<<endl;
    wyniki<<endl;
}

void zad2()
{
    wyniki<<"zad 4.2\n";
    cout<<"zad 4.2\n";

    vector<int> sito(1300001, 0);
    sito[0] = 1;
    sito[1] = 1;

    for(int i =2; i<=sqrt(1300000); i++)
    {
        if(sito[i] == 0)
        {
            for(int j = i*i; j<=sqrt(1300000); j+=i)
            {
                sito[j] = 1;
            }
        }
    }


    ifstream dane("pierwsze.txt");
    while(!dane.eof())
    {
        int x;
        dane>>x;
        int liczba = 0, remainder, org =x;

        while(x != 0)
        {
            remainder = x%10;
            liczba = liczba*10 + remainder;
            x /= 10;
        }
        cout<<org<<" "<<liczba<<endl;
        if(sito[org] == 0 && sito[liczba] == 0)
            cout<<org<<" ";
    }
    cout<<"zapisano"<<endl;
    wyniki<<endl;
    dane.close();
}

int main()
{
    ifstream plik("liczby.txt");

    while(!plik.eof())
    {
        int x;
        plik>>x;
        liczby.push_back(x);
    }
    wyniki<<"zad 4.1\n";
    zad1();
    zad2();

    plik.close();
    return 0;
}
