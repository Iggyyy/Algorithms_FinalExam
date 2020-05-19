#include <bits/stdc++.h>

using namespace std;


int nwd(int a, int b)
{
    while(b!=0)
    {
        int x = a % b;
        a = b;
        b = x;
    }
    return a;
}
int nww(int a, int b)
{
    return a*b/nwd(a,b);
}
int toDec(int a)
{
    int dec = 0;
    int it  =0;
    while(a)
    {
        int r = a%10;
        dec += r * pow(2, it);
        a/=10;
        it++;
    }
    return dec;
}
int DecToSys(int dec, int sys)
{
    int num = 0;
    int it = 1;
    while(dec)
    {
        num += dec%sys*it;
        dec/=sys;
        it*=10;
    }
    return num;
}
float horner(vector<int> wsp, int x, int st)
{
    if(st == 0)
        return wsp[0];

    return x * horner(wsp, x, st-1) + wsp[st];
}
void bSort(vector<int> tab)
{
    int n  = tab.size();
    for(int i =  0 ; i <n; i++)
    {
        for(int j  = 0; j<n-1; j++)
        {
            if(tab[j] > tab[j+1])
                swap(tab[j], tab[j+1]);
        }
    }
    for(int i : tab)
        cout<<i<<" ";
    cout<<endl;
}
void iSort(vector<int> tab)
{
    for(int i =  1; i< tab.size(); i++)
    {
        int tmp = tab[i];
        int j = i -1;
        while(tmp < tab[j] && j>=0)
        {
            tab[j+1] = tab[j];
            j--;
        }
        tab[j+1] = tmp;
    }




    for(int i : tab)
        cout<<i<<" ";
    cout<<endl;

}
int bSearch(vector<int> tab,int x, int l, int r)
{
    //int mid = (l+r)/2;
    while(l<=r)
    {
        int mid = (l+r)/2;
        if(tab[mid] == x)
            return mid;
        else if(tab[mid] > x)
            r = mid-1;
        else
            l = mid;
    }

    return -1;

}



int main()
{

    cout<<nwd(5,20)<<endl;
    cout<<nww(5,30)<<endl;
    cout<<toDec(1000)<<endl;
    cout<<DecToSys(7, 2)<<endl;
    cout<<horner({2,1,3}, 2, 2)<<endl;
    bSort({3,4,2,5,6,1});
    iSort({3,4,2,5,6,1});
    cout<<bSearch({1,2,3,4,5,6,7,8,9}, 9, 0, 9)<<endl;


    return 0;
}
