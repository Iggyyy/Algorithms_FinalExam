#include <bits/stdc++.h>
using namespace std;

vector<string> slowa;
vector<int> klucze;

string zaszyfruj(string A, vector<int> P)
{
    int n = A.size();
    A = " " + A;
    for(int i =1; i<=n; i++)
    {

        swap(A[i], A[P[1 + (i-1)%n]]);
        //cout<<1 + (i-1)%n<<" ";
        //cout<<A[50]<<endl;
    }
    A.erase(0, 1);
    return A;
}
vector<int> wydluzKlucz(vector<int> P, int S)
{
    int orgSize = P.size()-1;
    int ile = S - P.size();
    int i = 1, it = 0;
    while(it <= ile)
    {
        //cout<<i<<endl;
        P.push_back(P[i]);
        i++;
        if(i > orgSize)
            i = 1;
        it++;
    }
    //cout<<endl;
    return P;
}
string odszyfruj(string A, vector<int> P)
{
    int n = A.size();
    A = " " + A;
    for(int i =n; i>=1; i--)
    {

        swap(A[i], A[P[1 + (i-1)%n]]);
        //cout<<1 + (i-1)%n<<" ";
        //cout<<A[50]<<endl;
    }
    A.erase(0, 1);
    return A;
}
void zad1()
{
    cout<<"ZAD1"<<endl;


    for(int i = 0; i< 6; i++)
    {
    klucze = wydluzKlucz(klucze, 100);
        cout<<zaszyfruj(slowa[i], klucze)<<endl;
    }

    cout<<endl;
}

void readOne()
{
    ifstream dane("szyfr1.txt");
    for(int i = 0; i<6; i++)
    {
        string s; dane>>s;
        slowa.push_back(s);
       // cout<<s<<endl;
    }
    klucze.push_back(0);
    for(int i = 0; i<50; i++)
    {
        int x;
        dane>>x;
        klucze.push_back(x);
       // cout<<atoi(x.c_str())<<" ";
    }
    dane.close();

}


void zad2()
{
    ifstream plik("szyfr2.txt");
    string napis; plik>>napis;
    vector<int> klucz;
    klucz.push_back(0);
    for(int i = 0; i< 15; i++)
    {
        int x; plik>>x;
        klucz.push_back(x);
    }
    plik.close();

    klucz = wydluzKlucz(klucz, 100);

    for(int i : klucz)
        cout<<i<<" ";
    string nowy = zaszyfruj(napis, klucz);
    cout<<"ZAD2\n"<<nowy<<endl;

}


void zad3()
{
    ifstream plik("szyfr3.txt");

    //vector<int> P = {0,3,2,5,4,1};
    //vector<int> s = wydluzKlucz(P, 50);
    string enc;
    plik>>enc;
    vector<int> klucz =  {0, 6,2,4,1,5,3};
    klucz = wydluzKlucz(klucz, 100);
    enc = odszyfruj(enc, klucz);


    cout<<enc<<endl;
    //cout<<odszyfruj(enc,s);


/*
    string out  = zaszyfruj("QWERTYUIOPLKMJNHBGVFCDXSZAqwertyuioplkjhgfdsaz",s);
    string orginal = "QWERTYUIOPLKMJNHBGVFCDXSZAqwertyuioplkjhgfdsaz";
    cout<< out<<endl;
    for(int i =0; i<100000; i++)
    {
        out = zaszyfruj(out, s);
       // cout<<i<< " "<<out<<endl;
        if(out == orginal)
        {
            cout<<i<< " "<<out<<endl;
            //break;
        }
    }
    */
}




int main()
{
    //vector<int> P = {0,3,2,5,4,1};
    //vector<int> s = wydluzKlucz(P, 11);
    //cout<<zaszyfruj("INFORMATYKA",s);

   // readOne();
    //zad1();
    //zad2();
    zad3();
    return 0;
}
