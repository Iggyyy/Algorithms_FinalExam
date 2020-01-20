#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;
vector<int> liczby;
ofstream wyniki("wyniki4.txt");

void zad4_1()
{
    int sum =0;
    for(int k = 0; k< liczby.size(); k++)
    {
        for(int i = 0; i< sqrt(liczby[k]); i++)
        {
            //cout<<pow(3,i)<<" "<<liczby[k]<<endl;

            if(pow(3,i) == liczby[k])
            {
                sum++;
                break;
            }
            else if(pow(3,i) > liczby[k])
            {
                break;
            }
        }
    }
    cout<<"ZAD 4.1\n"<<sum<<endl;
    wyniki<<"ZAD 4.1\n"<<sum<<endl;

}

int silnia(int a)
{
    int sum = 1;

    while(a>0)
    {
        sum*=a;
        a--;
    }

    return sum;
}

void zad4_2()
{
    cout<<"ZAD 4.2\n";
    wyniki<<"ZAD 4.2\n";

    for(int i =0; i<liczby.size(); i++)
    {
        int licz = liczby[i], sum = 0;
        while(licz > 0)
        {
            sum += silnia(licz%10);
            licz/=10;
        }
        if(sum == liczby[i])
        {
            cout<<liczby[i]<<endl;
            wyniki<<liczby[i]<<endl;
        }
    }
}

int NWD(int a, int b)
{
    while(a > 0)
    {
        int c = a;
        a = b % a;
        b = c;
    }
    return b;
}

void zad4_3()
{
    int len = 0, dziel = 0, pierw = 0;
    for(int i =0; i<liczby.size()-2; i++)
    {
        int dl = 2, dz = NWD(liczby[i], liczby[i+1]);

        for(int j = i+1; j< liczby.size()-1; j++)
        {

            if(NWD(liczby[j],dz) == dz && NWD(liczby[j],dz) > 1)
                {
                    dl++;
                    dz = NWD(liczby[j],dz);

                }
            else
                break;
        }

        if(dl > len)
        {
            len = dl;
            dziel = dz;
            pierw = liczby[i];
        }

    }
    cout<<"ZAD 4.3\n"<<len<<" "<<dziel<<" "<<pierw<<endl;
    wyniki<<"ZAD 4.3\n"<<len<<" "<<dziel<<" "<<pierw<<endl;
}

int main()
{
    ifstream plik("liczby.txt");
    while(!plik.eof())
    {
        int a;
        plik>>a;
       // cout<<a;
        liczby.push_back(a);
    }

    zad4_1();
    zad4_2();
    zad4_3();

    plik.close();
    wyniki.close();
    return 0;
}
