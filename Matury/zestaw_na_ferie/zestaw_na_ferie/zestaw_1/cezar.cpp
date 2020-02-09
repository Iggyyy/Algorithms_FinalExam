#include <bits/stdc++.h>
using namespace std;



void zad1()
{
    ifstream dane("dane_6_1.txt");
    ofstream wyniki("wyniki_6_1.txt");
    int k = 107% ('Z' - 'A' + 1);
    cout<<"Zad 6.1\nklucz "<<k<<endl;
    wyniki<<"Zad 6.1\n";

    while(!dane.eof())
    {
        string slowo;
        dane>>slowo;
        string nowe = "";

        for(int i =0; i<slowo.length(); i++)
        {
            if(slowo[i] + k <= 'Z')
            {
                nowe += slowo[i] + k;
            }
            else
            {
                int nk = k - ('Z' - slowo[i] + 1);
                nowe += 'A' + nk;
            }

        }

        wyniki<<nowe<<endl;

    }





    wyniki.close();
    dane.close();
}

void zad2()
{
    ifstream dane("dane_6_2.txt");
    ofstream wyniki("wyniki_6_2.txt");
    cout<<"Zad 6.2"<<endl;
    wyniki<<"Zad 6.2\n";

    int it = 0;

    while(!dane.eof() && it<=717)
    {
        string slowo, nowe = "";
        int k;
        dane>>slowo>>k;

        k = k % 26;

        for(int i =0; i<slowo.length(); i++)
        {
            if(slowo[i] - k >= 'A')
            {
                nowe += slowo[i] - k;
            }
            else
            {
                int nk =  k - (slowo[i] - 'A' + 1);
                nowe += 'Z' - nk;
            }


        }

        wyniki<<nowe<<endl;
        it++;

    }


    dane.close();
    wyniki.close();
}

void zad3()
{
    ifstream dane("dane_6_3.txt");
    ofstream wyniki("wyniki_6_3.txt");
    cout<<"Zad 6.3"<<endl;
    wyniki<<"Zad 6.3\n";

    while(!dane.eof())
    {
        string slowo, drugie;
        dane>>slowo>>drugie;
        int k;
        if(slowo[0] <= drugie[0])
              k = drugie[0] - slowo[0];
        else
            k = ('Z' - slowo[0]) + (drugie[0] - 'A') + 1;


        bool jest = true;

        for(int i =1; i<slowo.length();i++)
        {
            int nk;
            if(slowo[i] <= drugie[i])
                nk = drugie[i] - slowo[i];
            else
                nk = ('Z' - slowo[i]) + (drugie[i] - 'A') + 1;

            if(nk != k)
                jest = false;
        }

        if(jest == false)
            wyniki<<slowo<<endl;
        //cout<<slowo<<" "<<drugie<<" "<<k<<endl;


    }





    dane.close();
    wyniki.close();
}

int main()
{


    zad1();
    cout<<"zapisano do pliku"<<endl;
    zad2();
    cout<<"zapisano do pliku"<<endl;
    zad3();
    cout<<"zapisano do pliku"<<endl;

    return 0;
}
