#include <iostream>
#include <bits/stdc++.h>
using namespace std;



int conv_from_dec(int liczba, int base)
{
    int num = 0;
    int d =1;
    while (liczba > 0)
    {
        num += (liczba % base)*d;
        liczba/=base;
        d*=10;
    }
    return num;
}

int conv_to_dec(int liczba, int base)
{
    int num=0;
    int it = 0;
    while(liczba > 0)
    {
        num += liczba%10 * pow(base, it);
        liczba/=10;
        it++;
    }
    return num;
}


int main()
{
    cout<<"Podaj liczbe do konwersji (systemy do dziesiatkowego): " <<endl;
    int a;
    cin>>a;

    cout << "Bin: "<<conv_from_dec(a,2) << endl;
    cout << "Octal: "<<conv_from_dec(a,8) << endl;
    cout << "Fours: "<<conv_from_dec(a,4) << endl;
    cout << "From bin to dec: "<<conv_to_dec(conv_from_dec(a,2),2) << endl;
    cout << "From oct to dec: "<<conv_to_dec(conv_from_dec(a,8),8) << endl;
    cout << "From four to dec: "<<conv_to_dec(conv_from_dec(a,4),4) << endl;
    return 0;
}
