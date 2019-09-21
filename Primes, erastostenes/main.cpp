#include <iostream>
#include <vector>
using namespace std;


void isPrime(int n)
{
    bool isprime = true;

    if(n < 2) isprime = false;
    else
    for(int i=2; i*i<n; i++)
    {
        if(n%i == 0)
        {
            isprime = false;
            break;
        }
    }

    if(isprime == true) cout<<"Prime"<<endl;
    else cout<<"Isn't"<<endl;
}

void primesToN(int n)
{
    vector<int> tab(n+1,0);

    for(int i = 2; i*i <= n; i++)
    {
        if(tab[i] == 0)
        {
            for(int j = i*i; j<=n; j+=i)
                tab[j] = 1;
        }
    }


    for (int i = 2; i<tab.size(); i++)
        if(tab[i] == 0 ) cout<<i<<endl;

}


void erastostostenes(int n)
{
    vector<int> tab(n+1, 0);
    //tab[0] = tab[1] = 1;

    for(int i =2; i*i<=n; i++)
    {

        if(tab[i] == 0)
        {
            for(int j = i*i; j<=n; j+=i)
                tab[j] = 1;
        }
    }

    for (int i = 2; i<tab.size(); i++)
        if(tab[i] == 0 ) cout<<i<<endl;




}







int main()
{
    int n;
    cout<<"N: "<<endl;
    cin >> n;
    isPrime(n);


    int nt;
    cout<<"Primes to n: "<<endl;
    cin>>nt;
    erastostostenes(nt);




    return 0;
}
