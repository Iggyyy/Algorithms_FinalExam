#include <bits/stdc++.h>
using namespace std;

vector<long long> liczby;

long long conv_to_dec(long long x, int base)
{
    long long dec = 0, i =0;
    //cout<<x<<" ";
    while(x>0)
    {
        int pom = x%10;
        dec += pom*pow(base,i);
        x/=10;
        i++;
    }
    //cout<<dec<<endl;
    return dec;
}
void zad1()
{
    int licznik = 0;
    for(int i =0 ; i <liczby.size(); i++)
    {
        if(liczby[i]%10 == 8)
            licznik++;
    }

    ofstream wynik("wyniki_6_1.txt");
    wynik<<licznik<<endl;

}

void zad2()
{
    int licznik = 0;
    for(int i =0 ; i <liczby.size(); i++)
    {
        if(liczby[i]%10 ==4)
            {
                long long x = liczby[i];
                bool jest = true;
                while(x>0)
                {
                    if(x%10 == 0)
                        jest = false;
                    x/=10;
                }
                if(jest == true) licznik++;
            }
    }

    ofstream wynik("wyniki_6_2.txt");
    wynik<<licznik<<endl;

}

void zad3()
{
    int licznik = 0;
    for(int i =0 ; i <liczby.size(); i++)
    {
        if(liczby[i]%10 == 2)
            {
                long long x = liczby[i]/=10;
                if(x%10 == 0)
                    {
                        licznik++;

                    }
            }
    }

    ofstream wynik("wyniki_6_3.txt");
    wynik<<licznik<<endl;

}

void zad4()
{
    long long sum = 0;
    for(int i =0 ; i <liczby.size(); i++)
    {
        if(liczby[i]%10 == 8)
            {
                long long x = liczby[i]/=10;
                sum += conv_to_dec(x,8);
            }
    }

    ofstream wynik("wyniki_6_4.txt");
    wynik<<sum<<endl;
}

void zad5()
{
    long long najwiek_k, najwiek_w = 0, najmniej_k, najmniej_w = 9e9;
    for(int i = 0; i<liczby.size(); i++)
    {
        long long x = liczby[i];
        int base = x%10;
        x/=10;
        long long decimal = conv_to_dec(x,base);

        if(decimal > najwiek_w)
        {
            najwiek_w = decimal;
            najwiek_k = liczby[i];
        }
        if(decimal < najmniej_w)
        {
            najmniej_w = decimal;
            najmniej_k = liczby[i];
        }


    }
    ofstream wyniki("wyniki_6_5.txt");
    wyniki<<"Najwieksza: "<<najwiek_k<<endl;
    wyniki<<"Najmniejsza: "<<najmniej_k<<endl;

}

int main()
{
    ifstream plik("liczby.txt");
    for(int i =0; i<999; i++)
    {
        long long a;
        plik >> a;
        liczby.push_back(a);


    }
      cout<<"wczytano"<<endl;
   //zad1();
   zad2();
  //zad3();
  // zad4();
  // zad5();

    return 0;
}
