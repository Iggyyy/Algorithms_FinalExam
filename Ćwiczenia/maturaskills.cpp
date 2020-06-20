#include <bits/stdc++.h>
using namespace std;


float horner(vector<float> wsp, float x, int st)
{
    if(st==0)
        return wsp[st];
    return x*horner(wsp,x,st-1) + wsp[st];
}
long long toDec(int num, int base)
{
    long long dec = 0;
    int it = 0;
    while(num)
    {
        dec += num%10*pow(base, it);
        num/=10;
        it++;
    }

    return dec;
}
int toSys(long long dec, int sys)
{
    int num = 0, it = 1;
    while(dec)
    {
        num+= dec%sys*it;
        dec/=sys;
        it*=10;
    }
    return num;
}
void bSort(vector<int> tab)
{
   for(int i = 0; i< tab.size(); i++)
   {
        for(int j = 0; j< tab.size()-1-i; j++)
        {
            if(tab[j] > tab[j+1])
                swap(tab[j], tab[j+1]);
        }


   }
    cout<<"sorted: ";
    for(int i : tab)
        cout<<i<<" ";
    cout<<endl;
}
string cezar(string slowo, int klucz)
{
    string nowe ="";
    klucz%=('Z' - 'A' + 1);
    for(int i = 0; i< slowo.size(); i++)
    {
        char c = slowo[i];

        if(klucz > 'Z' - c)
        {
            c = 'A' + klucz - ('Z' - c +1);
        }
        else
        c+=klucz;

        nowe.push_back(c);

    }



    return nowe;
}


int main()
{
    cout<<"horner: "<<horner({1,1,1,2}, 2,3 )<<endl;
    cout<<"conv to dec: "<<toDec(1011, 2)<<endl;
    cout<<"to sys: "<<toSys(11, 2)<<endl;
    vector<int> t = {2,4,7,2,5,8,3};
    bSort(t);
    cout<<cezar("ABCXYZ", 2);




    return 0;
}
