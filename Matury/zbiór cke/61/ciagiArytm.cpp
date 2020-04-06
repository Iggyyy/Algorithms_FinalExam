#include <bits/stdc++.h>
using namespace std;

vector< vector<int> > ciagi(100);
int najr = 0;


bool czyAryt(vector<int> ciag)
{
    //bool good = true;
    if(ciag.size() < 2) return false;
    int r = ciag[1] - ciag[0];
   // cout<<r<<endl;
    for(int i = 0; i<ciag.size()-1; i++)
    {
        //cout<<ciag[i+1] - ciag[i]
        if(ciag[i+1] - ciag[i] != r) return false;
    }
    najr=max(r,najr);
    return true;
}
void zad1()
{
    int counter = 0;

    for(int i =0; i<100; i++)
    {
        if(czyAryt(ciagi[i])) counter++;
    }

    cout<<"ZAD1"<<endl<<"Liczba ciagow: "<<counter<<endl<<"Najwieksza roznica: "<<najr<<endl;

}
bool czySzesc(int x)
{
    for(int i = 1; i*i*i<=x; i++)
    {
        if(i*i*i == x) return true;
    }

    return false;
}
void zad2()
{
    cout<<"ZAD2"<<endl;
    for(int i = 0; i<100; i++)
    {
        vector<int> ciag = ciagi[i];
        int najSzesc = -1;
        for(int j = 0; j<ciag.size(); j++)
        {
            //cout<<"ss"<<endl;
            if(czySzesc(ciag[j])) najSzesc = max(ciag[j], najSzesc);
        }
        if(najSzesc != -1) cout<<najSzesc<<endl;
    }


}


void WypiszBlad(vector<int> ciag)
{
    int counter = 0;
    int firstIndex = -1;
   for(int i = 1; i<ciag.size()-1; i++)
   {
       if(ciag[i]*2 != ciag[i-1] + ciag[i+1])
       {
        counter++;
        if(firstIndex < 0) firstIndex = i;
           //cout<<ciag[i]<<endl;
       }
   }

   if(counter == 1){
        if(firstIndex == 1)
            cout<<ciag[firstIndex-1]<<endl;
        else
        cout<<ciag[firstIndex+1]<<endl;
   }
    else
        cout<<ciag[firstIndex+1]<<endl;




    //cout<<" "<<endl;
}

void zad3()
{
    cout<<"ZAD3"<<endl;

    ifstream plik("bledne.txt");
      for(int i = 0; i < 20; i++)
    {
        vector<int> bledne;
        int c; plik >> c;
        for(int j = 0; j<c; j++)
        {
            int x; plik >> x;
            bledne.push_back(x);


        }
        cout<<i+1<<". ";
        WypiszBlad(bledne);
    }

}


int main()
{
    ifstream plik("ciagi.txt");
    for(int i = 0; i < 100; i++)
    {
        int c; plik >> c;
        for(int j = 0; j<c; j++)
        {
            int x; plik >> x;
            ciagi[i].push_back(x);
        }

    }

    zad1();
    cout<<endl;
    zad2();
    cout<<endl;
    zad3();

    return 0;
}
