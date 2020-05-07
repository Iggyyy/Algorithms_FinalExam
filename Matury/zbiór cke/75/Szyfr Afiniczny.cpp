#include <bits/stdc++.h>

using namespace std;

vector<string> slowa;

string szyfruj(string wyraz, int A, int B)
{
    string zaszyfr = "";
    for(int i = 0; i<wyraz.size(); i++)
    {
        int liczba = wyraz[i] - 'a';
        int nowa = liczba * A + B;
        if(nowa > 25)
            nowa= nowa % 26;
        char a = 'a' + nowa;
        zaszyfr.push_back(a);

    }

    //cout<<zaszyfr<<endl;

    return zaszyfr;
}

void zad1()
{
    int counter = 0;
    for(int i = 0; i<slowa.size(); i++)
    {
        if(slowa[i][0] == 'd' && slowa[i][slowa[i].length()-1] == 'd')
        {
            counter++;
            //cout<<slowa[i]<<endl;
        }
    }
    cout<<"ZAD1\n"<<counter<<endl;
}

void zad2()
{
    cout<<"ZAD2"<<endl;
    for(string wyraz : slowa)
    {
        if(wyraz.length() >= 10)
        {
            cout<<szyfruj(wyraz, 5, 2)<<endl;
        }

    }

}

void wypiszKlucze(string orginal, string zaszyfr)
{
    bool szyfr = false, deszyfr = false;
    for(int i = 0; i<26; i++)
    {
        for(int j = 0; j<26; j++)
        {
            if(szyfr == false)
            {
                string probka = szyfruj(orginal, i, j);
                if(probka == zaszyfr)
                {
                    szyfr = true;
                    cout<<orginal<<" "<<i<<" "<<j<<" ";
                }
            }
            if(deszyfr == false)
            {
                string probka = szyfruj(zaszyfr, i, j);
                if(probka == orginal)
                {
                    deszyfr == true;
                    cout<<zaszyfr<<" "<<i<<" "<<j<<" ";
                }

            }
        }

    }
    cout<<endl;


}

void zad3()
{
    cout<<"ZAD3"<<endl;
    ifstream plik("probka.txt");
    while(!plik.eof())
    {
        string org, szyf;
        plik>>org>>szyf;
        wypiszKlucze(org, szyf);

    }
    plik.close();
}




int main()
{
    ifstream plik("tekst.txt");
    while(!plik.eof())
    {
        string wyraz;
        plik>>wyraz;
        slowa.push_back(wyraz);
       // cout<<wyraz<<endl;
    }
    plik.close();



    zad1();
    cout<<endl;
    zad2();
    cout<<endl;
    zad3();

   // cout<<"TESTY____________________"<<endl;
    //cout<<szyfruj("yfjl", 25, 13);


    return 0;
}
