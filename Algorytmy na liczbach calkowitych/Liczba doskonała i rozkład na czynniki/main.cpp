#include <iostream>

using namespace std;




bool czyDoskolnala(int liczba)
{
    bool doskonala = false;
    int sum =0;
    for(int i = liczba-1; i>0; i--)
    {
        if(liczba % i == 0) sum+=i;
        cout<<i<<endl;
    }

    if(sum == liczba) doskonala = true;

    return doskonala;
}

void rozkladNaCzynPierwsz(int liczba)
{
    int k = 2;
    while(liczba > 1)
    {
        while(liczba%k == 0)
        {
                cout<<k<<endl;
                liczba/=k;
        }
        k++;
    }
}

int main()
{
    cout<<"Prosze podac liczbe: "<<endl;
    int a;
    cin>>a;
    cout<<((czyDoskolnala(a) == true )? "doskonala" : "niedosk.")<<endl<<endl;


    cout<<"liczba "<<a<<" na czynniki pierwsze"<<endl;
    rozkladNaCzynPierwsz(a);

    return 0;
}
