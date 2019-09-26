#include <iostream>

using namespace std;


int quickPow(int base, int pow)
{
    int res = 1;

    while(pow>0)
    {
        if(pow%2 == 1)
            res*=base;

        base*=base;
        pow/=2;
    }
    return res;
}



int main()
{
    cout<<"Podaj liczbe do potegowania: "<<endl;
    int a,b;
    cin>>a;
    cout<<"Podaj potege: "<<endl;
    cin>>b;

    cout<<"Pow: "<<quickPow(a,b);

    return 0;
}
