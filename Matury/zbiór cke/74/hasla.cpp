#include <bits/stdc++.h>
using namespace std;
ofstream wyniki;
vector<string> hasla;


void zad1()
{
    int licznik = 0;
    for(int i =0; i<hasla.size(); i++)
    {
        bool jest = true;
        for(int j =0; j<hasla[i].size(); j++)
        {
            if((char)hasla[i][j] < '0' || (char)hasla[i][j] > '9')
                jest = false;
        }
        if(jest) licznik++;

    }
    cout<<"Zad 1:\n"<<licznik<<endl;
    wyniki<<"Zad 1:\n"<<licznik<<endl;

}

void zad2()
{
    vector<string> dupl;
    cout<<"ZAD 2:\n"; wyniki<<"ZAD 2:\n";
    for(int i =0; i<hasla.size(); i++)
    {
        for(int j = i+1; j<hasla.size()-1; j++)
        {
            if(hasla[i] == hasla[j])
            {
                bool dodac = true;
                for(int k =0; k<dupl.size(); k++)
                    if(hasla[i] == dupl[k]) dodac = false;

                if(dodac) dupl.push_back(hasla[i]);
            }
        }
    }

    for(int i = 0; i<dupl.size(); i++)
        {
            cout<<dupl[i]<<endl;
            wyniki<<dupl[i]<<endl;
        }


}

void zad3()
{
    int licznik = 0;
    for(int i =0; i<hasla.size(); i++)
    {
        string haslo = hasla[i];

        for(int j = 0; j<haslo.size()-3; j++)
        {
            int jeden = 0, dwa = 0, trzy = 0;

            for(int k = 1; k<4; k++)
            {
                if(abs(haslo[j] - haslo[k]) == 1)
                    jeden++;
                if(abs(haslo[j] - haslo[k]) == 2)
                    dwa++;
                if(abs(haslo[j] - haslo[k]) == 3)
                    trzy++;

            }

            if(jeden == 1 && dwa == 1 && trzy == 1)
            {
                licznik++;
                break;
            }
        }

    }
    wyniki<<"ZAD 3:\n"<<licznik<<endl;
    cout<<"ZAD 3:\n"<<licznik<<endl;

}

void zad4()
{
    int licznik = 0;
    for(int i =0 ;i<hasla.size(); i++)
    {
        string haslo = hasla[i];
        bool liczba = false, duza = false, mala = false;
        for(int j = 0; j<haslo.size(); j++)
        {
            if((char)haslo[j] >= 'A' && (char)haslo[j] <= 'Z')
                duza++;
            else if((char)haslo[j] >= 'a' && (char)haslo[j] <= 'z' )
                mala++;
            else if((char)haslo[j] >= '0' && (char)haslo[j] <= '9' )
                liczba++;


        }

        if(liczba == true && duza == true && mala == true) licznik++;


    }
    cout<<"ZAD 4:\n"<<licznik<<endl;
    wyniki<<"ZAD 4:\n"<<licznik<<endl;


}


int main()
{
    wyniki.open("wyniki.txt");
    ifstream dane("hasla.txt");
    while(!dane.eof())
    {
        string line;
        dane>>line;
        hasla.push_back(line);
    }

    zad1();
    zad2();
    zad3();
    zad4();





    wyniki.close();
    return 0;

}
