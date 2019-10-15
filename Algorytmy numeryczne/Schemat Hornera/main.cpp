#include <iostream>
#include <bits/stdc++.h>

using namespace std;




int horner(vector<int> wsp, int st, int x)
{

    if(st==0)
        return wsp[0];

    return horner(wsp, st-1, x)*x + wsp[st];

}


int hornerINT(vector<int> wsp,int st, int x)
{
	if(st==0)
		return wsp[0];

	return x*horner(wsp,st-1,x)+wsp[st];
}

int hornerPractice(vector<int> wsp, int stopien, int x)
{
    if(stopien == 0)
        return wsp[0];
    return hornerPractice(wsp, stopien-1, x)*x + wsp[stopien];
}


int main()
{
    vector<int> wsp;
    cout<<"Podaj stopien wielomianu: ";
    int a;
    cin>>a;
    for (int i =a; i>=0 ;i--)
    {
        cout<<"Wczytaj wartosc wspolczynnika przy potedze "<<i<<": ";
        int t; cin>>t;
        wsp.push_back(t);
    }
    cout<<"Podaj wartosc dla jakiej obliczyc wielomian: ";
    int x;
    cin>>x;
    cout<<horner(wsp,a,x)<<'\n';
    cout<<hornerINT(wsp,a,x)<<'\n';
    cout<<hornerPractice(wsp,a,x)<<'\n';

    return 0;
}
