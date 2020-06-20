#include <bits/stdc++.h>
using namespace std;


int main()
{
    vector<int> A = {5,99,3,7,111,13,4,24,4,8};
    int n  = 10;
    int l  =  0, r = n-1, s;
    while(l<r)
    {
        s= (l+r)/2;
        if(A[s] %2 == 1)
            l = s+1;
        else
            r = s;
    }
    cout<<A[l]<<endl;

    l = 0;
    r = n-1;


    while(l<=r)
    {
        s = (l+r)/2;
        if(A[s] %2 == 0 && A[s+1]%2 == 0)
        {
            cout<<A[s];
            break;
        }
        else if(A[s]%2 == 1 && A[s+1]%2 == 1)
            l = s+1;
        else
            r =s;
    }




    return 0;
}
