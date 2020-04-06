#include <bits/stdc++.h>
using namespace std;

vector<string> slowoP, slowoD;




bool czyJedAnag(string pier, string drug)
{
    if(pier.length() != drug.length()) return false;

    vector<int> literkiP(26, 0), literkiD(26, 0);
    for(int i =0; i< pier.size(); i++)
    {
        literkiP[pier[i]%26]++;
        literkiD[drug[i]%26]++;
    }
    int counterP = 0;
    int counterD = 0;
    for(int i = 0; i<26; i++)
        {
            if(literkiP[i] != 0) counterP++;
            if(literkiD[i] != 0) counterD++;
        }

    if(counterP > 1 || counterD >1) return false;

    //cout<<pier<<" "<<drug<<endl;
    return true;

}
void zad1()
{
    int counter = 0;
    for(int i =0; i<slowoP.size(); i++)
    {
        if(czyJedAnag(slowoP[i], slowoD[i])) counter++;
    }
    cout<<"Zadanie 1:\n"<<counter<<endl;
}
bool czyAnag(string pier, string drug)
{
    if(pier.length() != drug.length()) return false;

    vector<int> literkiP(26, 0), literkiD(26, 0);
    for(int i =0; i< pier.size(); i++)
    {
        literkiP[pier[i]%26]++;
        literkiD[drug[i]%26]++;
    }
    for(int i =0; i<26; i++)
        if(literkiP[i] != literkiD[i]) return false;

    return true;
}
void zad2()
{
    cout<<"Zadanie 2:\n";
    int counter = 0;
    for(int i = 0; i<slowoD.size(); i++)
    {
        if(czyAnag(slowoD[i], slowoP[i])) counter++;

    }
    cout<<counter<<endl;

}

int ileAnagr(string slowo)
{
    int ile = 0;


    for(int i = 0 ; i<slowoP.size(); i++)
    {
       ile =  czyAnag(slowo, slowoP[i]) ? ile + 1 : ile;
       ile =  czyAnag(slowo, slowoD[i]) ? ile + 1 : ile;
    }


    return ile;
}

void zad3()
{
    cout<<"Zadanie 3:"<<endl;
    int najwiecej = 0;
    vector<string> psort, dsort;
    psort =  slowoP;
    sort(psort.begin(), psort.end());
    dsort = slowoD;
    sort(dsort.begin(), dsort.end());

    for(int i = 0 ; i< slowoP.size(); i++)
        najwiecej = max(najwiecej, ileAnagr(slowoP[i]));
    //for(int i = 0 ; i< slowoD.size(); i++)
      //  najwiecej = max(najwiecej, ileAnagr(slowoD[i]));

    cout<<najwiecej<<endl;


}

int main()
{
    ifstream plik("dane_napisy.txt");
    while(!plik.eof())
    {
        string line; plik>>line;
        slowoP.push_back(line);
        string drugie; plik>>drugie;
        slowoD.push_back(drugie);
    }

    zad1();
    zad2();
    zad3();

}
