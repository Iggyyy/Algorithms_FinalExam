#include <bits/stdc++.h>

using namespace std;

ofstream wyniki;

void zad1()
{
    ifstream plik("hasla.txt");
     int counter =0;
    while(!plik.eof())
    {
        string first, second;
        plik>>first>>second;


        vector<int> f(26,0);
        vector<int> s(26,0);



        if(first.length() == second.length())
        {
            for(int i =0; i<first.length(); i++)
            {
                f[first[i]%26]++;
                s[second[i]%26]++;
            }
            bool anag = true;

            for(int i =0; i<26; i++)
            {
                if(s[i] != f[i])
                    anag = false;
            }

            if(anag == true)
                counter++;
        }

    }

    cout<<"zad1:\n"<<counter<<endl;


    wyniki<<"zad1:\n"<<counter<<endl;

    plik.close();
}

void zad2()
{
    vector<string> combs;
    combs.push_back("ABC");
    combs.push_back("ACB");
    combs.push_back("BCA");
    combs.push_back("BAC");
    combs.push_back("CBA");
    combs.push_back("CAB");
    vector<int> counters(6,0);

    ifstream plik("hasla.txt");

    cout<<"zad2:\n";
        wyniki<<"zad2:\n";

    while(!plik.eof())
    {
        string haslo;
        plik>>haslo;
        //cout<<haslo<<" ";
        vector<int> spr(6,0);


            for(int k = 0; k<6; k++)
            {
               size_t found = haslo.find(combs[k]);
               while(found != string::npos)
                {
                    found = haslo.find(combs[k], found+1);
                    spr[k]++;
                    counters[k]++;
                    //cout<<found;
                }

            }


        bool great = false;
        for(int j = 0; j<6; j++)
        {
            if(spr[j] > 1)
                {
                    great = true;
                }
        }


        if(great == true)
            {
                cout<<haslo<<endl;
                wyniki<<haslo<<endl;
            }
       // cout<<endl;


    }

    plik.close();
}

void zad3()
{
    vector<int> literki(256,0);

    ifstream plik("hasla.txt");
    while(!plik.eof())
    {
        string haslo;
        plik>>haslo;

        for(int i =0; i<haslo.length(); i++)
        {
            literki[haslo[i]]++;
        }


    }
    int maks = 0, minim = 90000;
    char mak = '$', mini = '$';

    for(int i = 'A'; i<'Z'; i++)
    {
        if(literki[i] > maks)
           {
              mak = (char)i;
              maks = literki[i];

           }
        if(literki[i] < minim)
        {
            mini = (char)i;
            minim = literki[i];
        }

    }

    cout<<"zad3:\n";
    wyniki<<"zad3:\n";
    bool czest = true, rzad =true;

    for(int i = 'A'; i<'Z'; i++)
    {
        if(literki[i] == maks && (char)i != mak)
        {
            wyniki<<"Brak litery wystepujacej najczesciej"<<endl;
            czest = false;
            break;
        }
        if(literki[i] == minim && (char)i != mini)
        {
            rzad=false;
            wyniki<<"Brak litery wystepujacej najrzadziej"<<endl;
            break;
        }
    }

    if(czest == true)
        wyniki<<"Najczesciej "<<mak<<endl;

    if(rzad == true)
        wyniki<<"Najrzadziej "<<mini<<endl;



    cout<<"zapisano do pliku"<<endl;
    plik.close();
}

int main()
{
    wyniki.open("wyniki4.txt");

    zad1();
    zad2();
    zad3();
    wyniki.close();
    return 0;
}
