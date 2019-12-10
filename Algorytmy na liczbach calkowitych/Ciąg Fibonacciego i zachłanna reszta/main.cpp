#include <iostream>
#include <vector>
using namespace std;


long long n_tyWyrazFibonacci(long long n)
{
    vector<long long> fibo;
    fibo.push_back(0);
    fibo.push_back(1);

    for(int i = 2; i<=n; i++)
    {
        fibo.push_back(fibo[i-1] + fibo[i-2]);
    }
    return fibo[n-1];
}


int fiboRecur(int n)
{
    if(n == 1) return 1;
    else if (n == 0) return 0;

    return fiboRecur(n-1) + fiboRecur(n-2);
}

void resztaZachlanna(int kwota)
{
    vector<int> banknoty{1,2,5,10,20,50,100,200,500};

    for(int i = banknoty.size()-1; i >=0; i--)
    {
        int ilosc = kwota / banknoty[i];
        if (ilosc > 0) cout<<ilosc<<"x "<<banknoty[i]<<endl;
        kwota%=banknoty[i];
    }
}





int main()
{
    cout<<"Podaj n dla ktorego wyznaczyc n-ty wyraz ciagu fibonacciego"<<endl;
    int a;
    cin>>a;
    cout<<n_tyWyrazFibonacci(a)<<endl;
    cout<<fiboRecur(a-1)<<endl;   //-1 BO INDEKS MUSI SIE ZGADZAC TAK JAKBY TABLICA

    cout<<"Podaj kwote reszty do wydania: "<<endl;
    int b;
    cin>>b;
    resztaZachlanna(b);


    return 0;
}
