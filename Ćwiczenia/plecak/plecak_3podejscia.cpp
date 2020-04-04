#include <bits/stdc++.h>
using namespace std;

void sortAsc(vector<int> &w, vector<int> &p)
{
     for(int i = 0; i<w.size()-1; i++)
    {
        for(int j = 0; j<w.size()-i-1; j++)
        {
            if(w[j] < w[j+1])
            {
                swap(w[j],w[j+1]);
                swap(p[j], p[j+1]);
            }
        }
    }

}
void sortDesc(vector<int> &w, vector<int> &p)
{
     for(int i = 0; i<w.size()-1; i++)
    {
        for(int j = 0; j<w.size()-i-1; j++)
        {
            if(w[j] > w[j+1])
            {
                swap(w[j],w[j+1]);
                swap(p[j], p[j+1]);
            }
        }
    }

}
void pakujPoWadze(int P, vector<int> w, vector<int> p)
{
    int  zapakowanoKG = 0, wartosc = 0;
    sortDesc(w,p);
    string wagi = "", wartosci ="";
    for(int i =0; i<w.size(); i++)
    {
       while(P >= w[i])
       {
           P -= w[i];
           zapakowanoKG += w[i];
           wartosc+=p[i];
           wagi+= to_string(w[i]) + " ";
           wartosci += to_string(p[i]) + " ";
       }
    }

    cout<<"ZAPAKOWANO: "<<zapakowanoKG<<" KG\nWARTOSC LACZNA: "<<wartosc<<" zl\nWartosci zapakowane: "<< wartosci<<"\nWagi zapakowane: "<<wagi<<endl;
}
void pakujPoWartosci(int P, vector<int> w, vector<int> p)
{
    int  zapakowanoKG = 0, wartosc = 0;
    sortAsc(p,w);
    string wagi = "", wartosci ="";
    for(int i =0; i<w.size(); i++)
    {
       while(P >= w[i])
       {
           P -= w[i];
           zapakowanoKG += w[i];
           wartosc+=p[i];
           wagi+= to_string(w[i]) + " ";
           wartosci += to_string(p[i]) + " ";
       }
    }

    cout<<"ZAPAKOWANO: "<<zapakowanoKG<<" KG\nWARTOSC LACZNA: "<<wartosc<<" zl\nWartosci zapakowane: "<< wartosci<<"\nWagi zapakowane: "<<wagi<<endl;
}

void pakujWartWaga(int P, vector<int> w, vector<int>p)
{
    int zapKG = 0, zapW = 0;
    string wagi = "", wartosci = "";
    vector<double> WW;
    for(int i =0; i< w.size(); i++)
    {
        WW.push_back((double)p[i]/(double)w[i]);
    }
    for(int i =0; i<WW.size()-1; i++)
    {
        for(int j =0; j<WW.size()- i -1; j++)
        {
            if(WW[i] < WW[i+1])
            {
                swap(WW[i], WW[i+1]);
                swap(w[i], w[i+1]);
                swap(p[i], p[i+1]);
            }
        }
    }

    for(int i =0; i<WW.size(); i++)
    {
        while(P >= w[i])
        {
            P -=w[i];
            zapKG += w[i];
            zapW += p[i];
            wagi += to_string(w[i]) + " ";
            wartosci += to_string(p[i] ) + " ";

        }
    }
     cout<<"ZAPAKOWANO: "<<zapKG<<" KG\nWARTOSC LACZNA: "<<zapW<<" zl\nWartosci zapakowane: "<< wartosci<<"\nWagi zapakowane: "<<wagi<<endl;
}



int main()
{
    vector<int> wi = {3 , 4 , 7, 11, 13, 17};
    vector<int> pi = {14, 25, 17, 20, 23, 45};
    int P = 23;
    cout<<"Po wadze, aby zmiescic jak najwiecej przedmiotow"<<endl;
   pakujPoWadze(P, wi, pi);
    cout<<"----------------------------------\nPo wartosci pakujemy od tych z najwieksza waga"<<endl;
   pakujPoWartosci(P, wi, pi);
   cout<<"-----------------------------------\nPakujemy po najlepszym wspolczynniku oplacalnosci wart/waga"<<endl;
   pakujWartWaga(P,wi,pi);

}
