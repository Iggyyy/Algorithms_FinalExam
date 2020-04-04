#include <bits/stdc++.h>
using namespace std;


vector< vector<int> > trojki(1000, vector<int>(3, 0));

void zad1()
{
    cout<<"ZAD1"<<endl;
    for(int i= 0; i<trojki.size(); i++)
    {
       int sumac = 0;
       int a = trojki[i][0], b = trojki[i][1];
       while(a>0)
       {
           sumac += a%10;
           a/=10;
       }
       while(b>0)
       {
           sumac+=b%10;
           b/=10;
       }
       if(sumac == trojki[i][2])
            cout<<trojki[i][0]<<" "<<trojki[i][1]<<" "<<trojki[i][2]<<endl;

    }

}


bool czyPierwsza(int a)
{
    if(a < 2) return false;
    for(int i = 2; i*i<=a; i++)
    {
        if(a%i == 0)
            return false;
    }
    return true;

}

void zad2()
{
    cout<<"\nZAD2"<<endl;
    for(int i = 0 ; i<trojki.size(); i++)
    {
        int a = trojki[i][0], b = trojki[i][1], c = trojki[i][2];
        if(czyPierwsza(a) && czyPierwsza(b) && c == a*b)
            cout<<a<<" "<<b<<" "<<c<<endl;
    }
}

bool czyTrP(int a, int b, int c)
{
    if( a*a + b*b == c*c || a*a + c*c == b*b || b*b + c*c == a*a)
        return true;
    return false;
}
void zad3()
{
    cout<<"\nZAD3"<<endl;
    vector<int> wiersze(1000);
    for(int i = 0 ; i<trojki.size(); i++)
    {
        int a = trojki[i][0], b = trojki[i][1], c = trojki[i][2];
        wiersze[i] = czyTrP(a,b,c);
        //cout<<wiersze[i]<< " ";
    }

    for(int i = 0; i< wiersze.size()-1; i++)
    {
        if(wiersze[i] == 1 && wiersze[i+1] == 1)
        {
            cout<<trojki[i][0]<<" "<<trojki[i][1]<<" "<<trojki[i][2]<<endl;
            cout<<trojki[i+1][0]<<" "<<trojki[i+1][1]<<" "<<trojki[i+1][2]<<endl<<endl;
        }
    }


}

bool czyBoki(int a, int b, int c)
{
    if(a+b > c &&  a+c > b && b+c > a)
        return true;
    return false;

}
void zad4()
{
    cout<<"ZAD4"<<endl;
    int counter = 0;
    vector<int> wersy(trojki.size());
    for(int i =0; i<wersy.size(); i++)
        wersy[i] = czyBoki(trojki[i][0], trojki[i][1], trojki[i][2]);

    int najdl = 0;
    for(int i = 0; i<wersy.size(); i++)
    {
        int dl = 0;
        if(wersy[i] == 1)
        {
            counter++;
            for(int j = i; j<wersy.size(); j++)
            {
                if(wersy[j] == 1)
                    dl++;
                else break;
            }
        }

        najdl = max(najdl, dl);
    }
    cout<<"Ciag: "<<najdl<<"\nIle wersow: "<<counter<<endl;

}


int main()
{
        ifstream plik("trojki.txt");
        for(int i = 0; i<1000; i++)
            for(int j = 0; j<3; j++)
            {
                int a;
                plik>>a;
                trojki[i][j] = a;
                //cout<<trojki[i][j]<<endl;
            }

        zad1();
        zad2();
        zad3();
        zad4();
      // cout<<czyTrP(3,5,4);

        plik.close();
        return 0;
}
