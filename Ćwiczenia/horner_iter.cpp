#include <bits/stdc++.h>
using namespace std;


float hornerIT(int x, vector<int> tab, int st)
{
    float result = tab[0];
    for(int i = 1; i<= st; i++)
    {
        result = result*x + tab[i];
    }



    return result;
}
float horner(int x, vector<float> tab, int st)
{
    if(st==0)
        return tab[0];
    return x*horner(x, tab, st-1) + tab[st];
}


int to_sys(int x, int sys)
{
    int out = 0, it = 1;
    while(x)
    {
        out += x%sys*it;
        x/=sys;
        it*=10;
    }
    return out;
}
int to_dec(int x, int from)
{
    int dec = 0, it = 0;
    while(x)
    {
        dec += x%10 * pow(from, it);
        it++;
        x/=10;
    }



    return dec;
}

string to_hex(int x)
{
    string hex = "";

    while(x)
    {
        int tmp = x%16;
        if(tmp > 9)
        {
            hex += 'A' + tmp-10;
        }
        else
            hex += to_string(tmp);
        x/=16;
    }
    reverse(hex.begin(), hex.end());
    return hex;
}

int hex_to_dec(string hex)
{
    int dec = 0, it = 0;
    for(int i  = hex.size()-1; i>=0; i--)
    {
        if(hex[i] >= 'A')
        {
            int tmp = 9+  hex[i] - 'A' + 1;
            dec += tmp*pow(16, it);
        }
        else
        {
            int tmp = hex[i] - '0';
            dec += tmp*pow(16, it);
        }
        it++;
    }



    return dec;
}



int main()
{
    int a = 123;
//    string s = stoi(a);
    cout<<hornerIT(3, {2,1,1}, 2)<<endl;
    cout<<horner(3, {2,1,1}, 2)<<endl;
    cout<<to_sys(13, 2)<<endl;
    cout<<to_dec(1101, 2)<<endl;
    cout<<to_hex(123)<<endl;
    cout<<hex_to_dec("7B")<<endl;


    return 0;
}
