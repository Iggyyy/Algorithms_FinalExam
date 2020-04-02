#include <bits/stdc++.h>
using namespace std;
vector<string> tekst;

bool czyDwie(string slowo)
{
    vector<int> literki(26,0);
    for(int i =0; i<slowo.size(); i++)
    {
        literki[slowo[i]%26]++;
    }
    for(int i =0; i<slowo.size(); i++)
        if(literki[i] > 1) return true;
    return false;

}
void zad1()
{
    int counter = 0;
    for(int i =0 ;i <tekst.size(); i++)
    {
        if(czyDwie(tekst[i])) counter++;
    }
    cout<<"Posiadajacych dwie takie same literki: "<<counter<<endl;
}
void zad2()
{
    int suma_liter = 0;
    vector<int> literki(256, 0);
    for(int i =0; i<tekst.size(); i++)
    {
        for(int j =0; j<tekst[i].size(); j++)
        {
            literki[tekst[i][j]]++;
            suma_liter++;
        }
    }

    for(int i = 'A'; i<='Z'; i++)
    {
        cout<<setprecision(3)<<(char)i<<" "<<setw(4)<<literki[i]<< setw(4)<<" ("<<((double)((int)(((double)literki[i]/(double)suma_liter*100)*100)))/100<<"%)"<<endl;
    }


}
bool czySamogl(char a)
{

    vector<char> samogloski = {'A', 'O', 'U', 'I', 'Y', 'E'};

    for(int i =0; i<samogloski.size(); i++)
        if(a == samogloski[i]) return false;
    return true;
}
int najdl_slowo(string slowo)
{
    int najdl = 0;

    for(int i =0; i<slowo.size(); i++)
    {
        int dl = 0;
        if(czySamogl(slowo[i]))
        {
            for(int j = i; j<slowo.size(); j++)
            {
                if(czySamogl(slowo[j]))
                    dl++;
                else break;
            }
        }
        if(dl > najdl)
            najdl = dl;

    }
    return najdl;
}
void zad3()
{
    int index, najdl = 0, ile = 0;
    for(int i =0; i<tekst.size(); i++)
    {
        int dl = najdl_slowo(tekst[i]);

        if(dl > najdl)
        {
            najdl = dl;
            index = i;
            ile = 1;
        }
        else if (dl == najdl)
        {
            ile++;
        }

    }
    cout<<"Pierwsze slowo: "<<tekst[index]<<" dlugosc: "<<najdl<<" ile takich slow: "<<ile<<endl;


}

int main()
{
    ifstream plik("tekst.txt");
    while(!plik.eof())
    {
        string slowo;
        plik>>slowo;
        tekst.push_back(slowo);
    }

    zad1();
    zad2();
    zad3();




    return 0;
}

