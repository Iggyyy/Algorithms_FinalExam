#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
vector<long long> liczby1;
vector<long long> liczby2;
vector<long long> conv2;
vector<long long> conv1;




int horner(vector<int> wsp, int stopien, int x)
{
    if(stopien == 0)
        return wsp[0];
    return x*horner(wsp,stopien-1, x) + wsp[stopien];
}

void zad1()
{
    int najw = liczby1[0], najw8,najm8, najm = liczby1[0];
    for(int i = 0; i< liczby1.size(); i++)
    {
        vector<int> wsp;
        int op = liczby1[i];

        while(op>0)
        {
            wsp.push_back(op%10);
            op/=10;
        }
        reverse(wsp.begin(), wsp.end());

       int value = horner(wsp, wsp.size()-1, 8);

    if(value > najw)
    {
        najw8 = liczby1[i];
        najw = value;
    }
    if(value < najm)
    {
        najm8 = liczby1[i];
        najm =value;
    }


    }
    cout<<"Najwieksza: "<<najw8<<"  Najmniejsza: "<<najm8<<endl;

}

void zad2()
{
    int naj = 0,index;
    for(int i =0; i<liczby2.size(); i++)
    {
        int prev = liczby2[i];
        int dl = 1;
        for(int j =i+1; j<liczby2.size(); j++)
        {
            if(liczby2[j] >= prev)
            {
                dl++;
                prev = liczby2[j];
            }
            else
                break;
        }

        if(dl > naj)
            {
                naj = dl;
                index = i;
            }


    }

    cout<<"Pierwsza: "<<liczby2[index]<<" dl: "<<naj<<endl;


}

void zad3()
{
    for(int i = 0; i<liczby1.size(); i++)
    {
       vector<int> wsp;
        int op = liczby1[i];

        while(op>0)
        {
            wsp.push_back(op%10);
            op/=10;
        }
        reverse(wsp.begin(), wsp.end());

       int value = horner(wsp, wsp.size()-1, 8);

       conv1.push_back(value);
    }
    //DWIE TAB W 10

    int tosamo = 0, wieksze = 0;
    for(int i = 0; i< liczby1.size(); i++)
    {
        if(liczby2[i] == conv1[i])
            tosamo++;
        if(conv1[i] > liczby2[i])
            wieksze++;
    }

    cout<<conv1[12]<<" "<<liczby2[12]<<endl;
    cout<<"Takich samych: "<<tosamo<<" Wiekszych: "<<wieksze;






}

int conv_to_octal(int base)
{
    int oct = 0, it = 0;

    while(base > 0)
    {
        int pom = base%8;
        oct = oct + pom*pow(10,it) ;
        base/=8;
        it++;
    }
    return oct;

}
void zad4()
{
    int ile_dec = 0, ile_oct = 0;

    for(int i =0; i< liczby2.size(); i++)
    {
        int x = liczby2[i];
        while(x > 0)
        {
            if(x%10 == 6)
                ile_dec++;
            x/=10;

        }
    }


    for(int i = 0 ; i<liczby2.size(); i++)
    {
        int x = conv_to_octal(liczby2[i]);

        while(x>0)
        {
            if(x%10 == 6)
                ile_oct++;
            x/=10;
        }
    }

    cout<<"\nw dec: "<<ile_dec<<" w oct: "<<ile_oct<<endl;

}


int main()
{
    ifstream dane("liczby1.txt");
    while(!dane.eof())
    {
        long long x; dane >> x;
        liczby1.push_back(x);
       //cout<<x<<endl;
    }
    dane.close();

    ifstream plik("liczby2.txt");
    while(!plik.eof())
    {
        long long x; plik >> x;
        liczby2.push_back(x);
       //cout<<x<<endl;
    }
    plik.close();

    cout<<"wczytano"<<endl;
    zad1();
    zad2();
    zad3();
    zad4();




    return 0;
}
