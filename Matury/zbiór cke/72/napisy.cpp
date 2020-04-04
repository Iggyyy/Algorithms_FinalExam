#include <bits/stdc++.h>
using namespace std;


vector<string> p, d;


void zad1()
{
    int counter= 0, pierIndex = -1;
    for(int i = 0; i<p.size(); i++)
    {
        int pl = p[i].size(), dl = d[i].size();
        if(pl >= 3*dl || dl >= 3*pl)
            {
                counter++;
                if(pierIndex < 0) pierIndex = i;
            }
    }
    cout<<"zad1\nIle: "<<counter<<"\nPierwszy wers: "<<p[pierIndex]<< " " << d[pierIndex]<<endl;


}
bool czyDaDop(string pierwszy, string drugi)
{
    if(pierwszy >= drugi) return false;

    for(int i = 0; i<pierwszy.size(); i++)
        if(pierwszy[i] != drugi[i])
            return false;
    return true;

}
void zad2()
{
    cout<<"zad2"<<endl;
    for(int i =0; i<p.size(); i++)
    {
        if(czyDaDop(p[i], d[i]))
        {
            cout<<"Wiersz: "<<p[i]<<" "<<d[i]<<endl;
            cout<<"Wspolny: "<<p[i]<< "\nDopisac: "<<d[i].substr(p[i].size(), d[i].size()-p[i].size()+1)<<endl<<endl;
        }
    }
}
int dlSufix(string a, string b)
{
    int dl = 0, ita = a.size()-1, itb = b.size()-1;
    while(ita >= 0 && itb >= 0)
    {
        //cout<<a[ita]<<" "<<b[itb]<<endl;
        if(a[ita] != b[itb])
            break;
        else dl++;
        ita--;
        itb--;
    }



    return dl;
}
void zad3()
{
    cout<<"ZAD3"<<endl;
    int najdl = 0;
    vector<int> dlugS(p.size(), 0);
    for(int i = 0; i<p.size(); i++)
    {
        najdl = max(najdl, dlSufix(p[i], d[i]));
        dlugS[i] = dlSufix(p[i], d[i]);
    }
    cout<<"Najdl: "<<najdl<<endl;

    for(int i = 0; i<p.size(); i++)
        if(dlugS[i] == najdl) cout<<p[i]<<" "<<d[i]<<endl;

}

int main()
{
    ifstream plik("napisy.txt");
    while(!plik.eof())
    {
        string a,b;
        plik>>a>>b;
        p.push_back(a);
        d.push_back(b);
    }
    zad1();
    zad2();
    zad3();


    plik.close();
    return 0;
}
