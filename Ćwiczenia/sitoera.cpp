#include <bits/stdc++.h>
using namespace std;





int main()
{
    int n = 500;
    vector<int> sito(n+1, 0);
    sito[0] = 1;
    sito[1] = 1;
    for(int i = 0; i*i<n+1; i++)
    {
        if(sito[i] == 0)
        {
            for(int j = i+i; j<n+1; j+=i)
            {
                sito[j] = 1;
            }
        }
    }


    for(int i = 0; i<n+1; i++)
    {
       (sito[i]  == 0) ? cout<<i<<endl : cout<<"";
    }

    return 0;
}
