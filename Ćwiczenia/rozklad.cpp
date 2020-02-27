#include <bits/stdc++.h>
using namespace std;


void podaj_czynniki(int a)
{
    int d = 2;
    while(a > 1 )
    {
        if(a%d==0)
        {
            a/=d;
            cout<<d<<" ";
        }
        else d++;

    }
    cout<<1<<endl;



}


int main()
{
    int x = 56;
    podaj_czynniki(x);


    return 0;
}
