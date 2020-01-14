#include <bits/stdc++.h>

using namespace std;

int ileRoznych(string line)
{
    int suma = 0;
    vector<int> znak(26,0);
    for(int i=0; i<line.length(); i++)
    {
        znak[line[i]%26]++;
    }
    //cout<<line<<endl;
    for(int i =0; i<26; i++)
    {
        if(znak[i] > 0)
            suma++;
    }
    return suma;
}

int maxOdleg(string slowo)
{
    int wmax =0, wmin = 100;
    for(int i =0; i<slowo.length(); i++)
    {
        if(slowo[i] > wmax)
            wmax = slowo[i];
        if(slowo[i] < wmin)
            wmin = slowo[i];
    }

    return wmax-wmin;
}

int main()
{
    ifstream plik("sygnaly.txt");
    ofstream wyniki("wyniki4.txt");
    vector<string> odleg;
    int i = 0, najl = 0;
    string slowo ="", najliter;
    while(!plik.eof())
    {
        string line;
        plik>>line;
        if(i == 39)
        {
            slowo+=line[9];
            i=0;
        }
        else
            i++;

        //cout<<ileRoznych(line)<<endl;
        if( ileRoznych(line) > najl)
        {

            najl = ileRoznych(line);
            najliter = line;
        }

        if(maxOdleg(line) <= 10)
        {
            odleg.push_back(line);
        }

    }

    wyniki<<"zad 4.1\n"<<slowo<<endl;
    wyniki<<"zad 4.2 \n"<<najl<<" "<<najliter<<endl;
    wyniki<<"zad 4.3 \n";
    for(int i =0; i<odleg.size(); i++)
        wyniki<<odleg[i]<<endl;



    plik.close();
    return 0;
}
