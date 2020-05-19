#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;



int conv_from_dec(int x, int to)
{
    int num = 0;
    while(x)
    {
        int pom = x%to;
        num = num*10 + pom;
        x/=to;
    }
    return num;
}

int conv_to_dec(int x, int from)
{
    int sum = 0, p = 0;

    while(x)
    {
        int pom = x%10;
        sum = sum + pom*pow(from,p);
        p++;
        x/=10;
    }
    return sum;
}

string dec_to_hex(int x)
{
    string hex ="";
    while(x)
    {
        int pom = x%16;
        char a;

        if(pom>9)
            a = 'A' + pom -10;
        else
            a = '0' + pom;

        hex.push_back(a);
        x/=16;
    }

    reverse(hex.begin(), hex.end());
    return hex;
}

int hex_to_dec(string hex)
{
    int dec =0, it = 0;

    for(int i =hex.length()-1;i>=0; i--)
    {
        if(hex[i] >= 'A')
            dec += (10 + hex[i] - 'A') * pow(16,it);
        else
            dec += (hex[i] - '0')*pow(16,it);
        it++;
    }


    return dec;
}



int main()
{
    int n = 16;
    cout<<conv_from_dec(n,2)<<endl;
    int x = 134501;
    cout<<conv_to_dec(x,2)<<endl;
    cout<<dec_to_hex(x)<<endl;
    string h = "25ABF";
    cout<<hex_to_dec(h)<<endl;

    return 0;
}
