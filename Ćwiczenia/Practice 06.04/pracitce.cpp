#include <bits/stdc++.h>

using namespace std;

int nwd(int a, int b)
{
    while(a!=b)
    {
        if(a > b)
            a-=b;
        else b-=a;
    }
    return a;
}

int nww(int a, int b)
{
    return a*b/nwd(a,b);
}


void selecSort(vector<int> &tab)
{
    for(int i  =0; i<tab.size()-1; i++)
    {
        int maxIndex = i;
        for(int j = i+1; j<tab.size(); j++)
        {
        //    cout<<tab[j]<<endl;
            if(tab[maxIndex] > tab[j]) maxIndex = j;
        }
        swap(tab[i], tab[maxIndex]);
    }
}
void insertSort(vector<int> &tab)
{

    for(int i = 1; i<tab.size(); i++)
    {
        int pom = tab[i];
        int j = i-1;
        while(pom < tab[j] && j>=0)
        {
            tab[j+1] = tab[j];
            j--;
        }
        tab[j+1] = pom;


    }

}
void bubbleSort(vector<int> &tab)
{
    for(int i = 0; i<tab.size(); i++)
        for(int j = i; j<tab.size(); j++)
        {
            if(tab[j] < tab[i]) swap(tab[i], tab[j]);
        }
}

int convToSystem(int x, int sys)
{
    int n = 0;
    int it = 1;
    while(x > 0)
    {
      n += x%sys*it;
      x/=sys;
      it*=10;
    }
    return n;
}
int convToDec(int x, int sys)
{
    int dec = 0;
    int pot = 0;
    while(x > 0)
    {
        dec+= x%10*pow(sys, pot);
        x/=10;
        pot++;
    }
    return dec;
}

float horner(vector<int> wsp, int stopien, float x)
{
        if(stopien == 0) return wsp[0];
        return x*horner(wsp, stopien-1, x) + wsp[stopien];
}


int main()
{
    cout<<nwd(8,60)<<endl;
    cout<<nww(6,7)<<endl;


    vector<int> licz = {1,5,6,2,4,6,7};
    selecSort(licz);
    for(int i : licz)
        cout<<i<<" ";
    cout<<endl;
    vector<int> liczby = {7,8,9,6,5,4,3,1,2};
    insertSort(liczby);
    for(int i : liczby)
        cout<<i<<" ";
        cout<<endl;

         vector<int> liczbyy = {7,8,9,6,5,4,3,1,2};
    bubbleSort(liczbyy);
    for(int i : liczbyy)
        cout<<i<<" ";

cout<<endl;
    cout<<convToSystem(16, 2)<<endl;
    cout<<convToDec(110011, 2)<<endl;

    vector<int> wsp = {1,2,3,4,5};
    cout<<horner(wsp, wsp.size()-1, 1.23429786f);


}
