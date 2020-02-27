#include <bits/stdc++.h>
using namespace std;

int horner(vector<int> wsp, int stopien, int x)
{
    if(stopien == 0)
        return wsp[0];
    return x*horner(wsp,stopien-1, x) + wsp[stopien];
}


int horner_iter(vector<int> wsp, int stopien, int x)
{
    int suma = 0;
    for(int i =0; i<=stopien; i++)
    {
        suma = suma * x + wsp[i];
    }

    return suma;
}



int _horner(vector<int> wsp, int stopien, int x)
{
    if(stopien == 0)
        return wsp[0];
    return x*_horner(wsp, stopien-1, x) + wsp[stopien];
}
int main()
{
    cout<<horner({2,1,3}, 2,3)<<endl;
    cout<<_horner({2,1,3}, 2,3)<<endl;
    cout<<horner_iter({2,1,3}, 2,3)<<endl;

}
