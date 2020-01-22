#include <bits/stdc++.h>

using namespace std;


void zad1(int n)
{
    //TWORZENIE SITA N LENGTH
    vector<int> sito(n+1, 0);
    sito[0] = 1;
    sito[1] = 1;
    for(int i = 2; i<sqrt(n); i++)
    {
        if(sito[i] == 0)
        {
            for(int j = i*i; j<=n; j=j+i)
            {
                sito[j] = 1;
            }
        }
    }
    ifstream dane("liczby.txt");
    ofstream wyniki("wyniki4.txt");
    wyniki<<"ZAD 4.1\n";
    cout<<"ZAD 4.1\n";

    while(!dane.eof())
    {
        int x;
        dane>>x;
        if(x>=100 && x<=5000)
        {
            if(sito[x] == 0)
            {
                cout<<x<<" ";
                wyniki<<x<<" ";
            }
        }
    }
    dane.close();
    wyniki.close();

}

void zad2(int n)
{
        //TWORZENIE SITA N LENGTH
    vector<int> sito(n+1, 0);
    sito[0] = 1;
    sito[1] = 1;
    for(int i = 2; i<sqrt(n); i++)
    {
        if(sito[i] == 0)
        {
            for(int j = i*i; j<=n; j=j+i)
            {
                sito[j] = 1;
            }
        }
    }
    ifstream dane("pierwsze.txt");
    ofstream wyniki("WYNIKI4.txt", ios::app);
    wyniki<<"\nZAD 4.2\n";
    cout<<"\nZAD 4.2\n";

    while(!dane.eof())
    {
        int x;
        dane>>x;
        cout<<"x: "<<x<<" ";
        if(sito[x] == 0)
        {
            int var = x, reversed = 0, reminder;
            while(var!=0)
            {
                reminder = var%10;
                reversed = reversed*10 + reminder;
                var/=10;

            }
            cout<<reversed;

            if(sito[reversed] == 0)
            {
                cout<<" Passed";
                wyniki<<reversed<<" ";
            }
        }
        cout<<endl;
    }
    dane.close();
    wyniki.close();
}

int sumaCyfr(int n)
{
    int suma = 0;

    while(n!=0)
    {
        suma = suma + n%10;
        n/=10;
    }

    return suma;
}

void zad3()
{
    fstream dane("pierwsze.txt");
    fstream wyniki("WYNIKI4.txt", ios::app);
    wyniki<<"\nZAD 4.3\n";
    cout<<"\nZAD 4.3\n";
    int licznik =0;
    while(!dane.eof())
    {
        int x;
        dane>>x;


        int sumaCyf = sumaCyfr(x);

        while(sumaCyf >=10)
        {
            //cout<<sumaCyf<<endl;
            sumaCyf = sumaCyfr(sumaCyf);
        }

        if(sumaCyf == 1)
            licznik++;
    }

    cout<<licznik<<endl;
    wyniki<<licznik<<endl;

    dane.close();
    wyniki.close();
}

int main()
{
    zad1(1300000);
    zad2(9999999);
    zad3();
    return 0;
}
