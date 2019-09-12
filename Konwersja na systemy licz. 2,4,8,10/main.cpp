#include <iostream>
#include <cmath>

using namespace std;


void Dec_to_bin(int liczba)
{
    int it= 1, bin = 0;
    while(liczba)
    {
        bin += liczba%2 * it;
        liczba/=2;
        it*=10;
    }
    cout<<bin<<endl;
}

void bin_to_dec(int bin)
{
    int it = 0, decimal = 0;
    while(bin)
    {
        decimal += bin%10 * pow(2, it);
        bin/=10;
        it++;
    }
    cout<<decimal<<endl;
}

void octal_to_dec(int octal)
{
    int it = 0, decimal =0;
    while(octal)
    {
        decimal += octal%10 * pow(8, it);
        octal/=10;
        it++;
    }
    cout<<decimal<<endl;
}

void dec_to_octal(int decimal)
{
    int it = 1, octal = 0;
    while(decimal)
    {
        octal += decimal%8 * it;
        decimal/=8;
        it*=10;
    }
    cout<<octal<<endl;
}


int main()
{
    cout<<"Decimal to binary: "<<endl;
    int a;
    cin>>a;
    Dec_to_bin(a);

    cout<<"Binary to decimal: "<<endl;
    int b;
    cin>>b;
    bin_to_dec(b);

    cout<<"Octal to decimal: "<<endl;
    int c;
    cin>>c;
    octal_to_dec(c);

    cout<<"Decimal to octal: "<<endl;
    int d;
    cin>>d;
    dec_to_octal(d);

    return 0;
}
