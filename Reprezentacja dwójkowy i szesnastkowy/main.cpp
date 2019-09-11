#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void decimalToBinary(int liczba)
{
    vector<int> bin;

    while(liczba)
    {
    bin.push_back(liczba%2);
    liczba/=2;
    }



    for(int i =bin.size()-1; i>=0; i--)
    {
        cout<<bin[i];
    }

    cout<<endl;
}

void BinaryToDecimal(int bin)
{
    int it=0, dec=0;

    while(bin)
    {
        dec += bin%10 * pow(2, it);
        bin/=10;
        it++;
    }

    cout<<dec<<endl;
}

void DecimalToHex(int dec)
{
    while(dec)
    {
        int op = dec%16;
        dec/=16;

        if(op>9)
        {
            cout<< (char)('A' + op-10);
        }
        else
            cout<<op;


    }
}

string DecimalToHexx(int liczba)
{
        if(liczba == 0) return "";

        string past = DecimalToHexx(liczba/16);
        int a = liczba%16;
        cout<<liczba<<endl;
        if(a > 9 )
             past += (char)('A' + a-10);
        else
             past += (char)a;

        return past;
}

int HexToDecimal(string liczba)
{
    int it = 0, sum = 0;
    for(int i = liczba.length()-1; i >= 0; i--)
    {
       sum += (int)liczba[i] * pow(16, it);

    }
    return sum;
}





int main()
{
    int a,b,c;
    string d;
    cin>>a;

    decimalToBinary(a);
    cin>>b;
    BinaryToDecimal(b);
    cin>>c;
    cout<<DecimalToHexx(c);
    cin>>d;
    cout<<HexToDecimal(d);

}
