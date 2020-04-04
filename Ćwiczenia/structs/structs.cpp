#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vecti;

struct rzecz{
    string nazwa;
    int waga;
    int cena;
};

void readThings(vector<rzecz> &tab)
{
    ifstream przedmioty("przedmioty.txt");
    while(!przedmioty.eof())
    {
        string n; int w, c;
        przedmioty>>n>>w>>c;
        rzecz p; p.nazwa = n; p.waga = w; p.cena = c;
        tab.push_back(p);
    }
}

int main()
{

    vector<rzecz> tab;
    readThings(tab);
    for(rzecz i : tab)
        cout<<i.nazwa<<endl;





    return 0;
}
