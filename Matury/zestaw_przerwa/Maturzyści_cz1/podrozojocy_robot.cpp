#include <bits/stdc++.h>
using namespace std;
vector< vector<int> > plansza(20, vector<int>(20, 0));
vector<string> ruchy;
vector<int> punkty;
ofstream wyniki;

//Metoda wczytujaca dane z plików
void load()
{
    //Wczytywanie planszy do wektora
    ifstream plansz("plansza.txt");
    for(int i =0; i<20; i++)
        for(int j =0; j<20; j++)
        {
            int a; plansz>>a;
            plansza[i][j] = a;
        }
   plansz.close();

    //Wczytywanie ruchow do wektora
   ifstream dane("robot.txt");
   while(!dane.eof())
   {
       string s; dane>>s;
       ruchy.push_back(s);

       //Wektor z punktami dla odpowiadajacego mu gracza
       punkty.push_back(0);
   }






   //Potwierdzenie wczytania
   cout<<"wczytano dane"<<endl;
}

//Aktualna pozycja podana przez referencje jest modyfikowana o ruch
void ruch(char literka, int &arow, int &acol)
{
    switch(literka)
    {
        case 'W':
            arow--;
            break;
        case 'E':
            arow++;
            break;
        case 'N':
            acol--;
            break;
        case 'S':
            acol++;
            break;

    }


}

//Realizacja zadania 1 i 2
void zad12()
{
    int licznik = 0;
    for(int i =0; i< ruchy.size(); i++)
    {
        string gracz = ruchy[i];
        int arow = 0, acol = 0, punkt = 0;
        for(int k = 0; k<gracz.size(); k++)
        {
            //Dodawanie punktów
            punkt += plansza[arow][acol];
            ruch(gracz[k], arow, acol); //wykonanie ruchu

            if(acol < 0 || acol >19 || arow < 0 || acol > 19)   //Warunek wyjscia za granice planszy -- dyskwalifikacja
            {
                licznik++; //zliczanie dyskwalifikacji
                punkt = -1;
               // cout<<arow<<"|"<<acol<<" ";
                break;

            }
        }
        //cout<<endl;
        punkty[i] = punkt;

    }
    cout<<"Zad 1:\n"<<licznik<<endl;
     wyniki<<"Zad 1:\n"<<licznik<<endl;
    //Szukanie najwiekszego wyniku punktowego
    int index, najw = 0;
    for(int i =0; i<punkty.size(); i++)
    {
        if(punkty[i] > najw)
        {
            najw = punkty[i];
            index = i;
        }
    }
    cout<<"Zad 2:\nIndex: "<<index<<" Wartosc: "<<najw<<endl;
    wyniki<<"Zad 2:\nIndex: "<<index<<" Wartosc: "<<najw<<endl;


}

//Zwraca dlugosc najwiekszego ciagu WE w stringu
int najCiagWiersz(string wiersz)
{
    int naj = 0;
    for(int i =0 ;i < wiersz.size(); i++)
    {
        int dl = 1;
        if(wiersz[i] == 'W' || wiersz[i] == 'E')
        {
            for(int j = i ;j < wiersz.size()-1; j++)
            {
                if(wiersz[j+1] == 'W' || wiersz[j+1] == 'E')
                    dl++;
                else break;
            }
            if(dl > naj)
                naj = dl;
        }

    }
    return naj;

}

//Realizacja zadania 3
void zad3()
{
    cout<<"Zad 3:\n";
    wyniki<<"Zad 3:\n";
    vector<int> wartosci;   //Przechowuje najwieksze wartosci dla danego gracza
    for(int i =0 ;i<ruchy.size(); i++)
    {
        int dl = najCiagWiersz(ruchy[i]);
        //cout<<dl<< " "<<ruchy[i]<<endl;
        wartosci.push_back(dl);
    }
    //Wyszukiwanie maxymalnej wartosci w tablicy
   int najd = 0;
   for(int i =0; i<wartosci.size(); i++)
   {

       if(wartosci[i] > najd)
        najd = wartosci[i];
   }

    //Wypisywanie graczy z najwieksza dlugoscia podciagow
    vector<int> indexy;
    for(int i = 0; i< wartosci.size(); i++)
    {
        if(wartosci[i] == najd)
            {
                cout<<"index: "<<i<<" wart:"<< wartosci[i]<<endl;
                wyniki<<"index: "<<i<<" wart:"<< wartosci[i]<<endl;
            }
    }


}

int main()
{
    wyniki.open("Zadanie4.txt");
    load();
    zad12();
    zad3();

    wyniki.close();
    return 0;
}
