#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


long long poteguj(int base, int power)
{
   long long wynik = 1;

   while(power > 0)
   {
       if(power %2 == 1)
            wynik *= base;

       base*=base;
        power/=2;
   }
    return wynik;
}


int main()
{
    cout<<"2 do 13"<<poteguj(2,13);

    return 0;
}
