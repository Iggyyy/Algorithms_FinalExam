#include <bits/stdc++.h>
using namespace std;


vector<vector<char> > siatka(14, vector<char>(22,40));



void ruch()
{

    vector<vector<char> > tmp;
    tmp = siatka;

    for(int i =1; i<13; i++)
    {

        for(int j =1; j<21; j++)
        {
            int ileSasiadow = 0;
            if(siatka[i+1][j-1] == 'X')
                ileSasiadow++;
            if(siatka[i+1][j] == 'X')
                ileSasiadow++;
            if(siatka[i+1][j+1] == 'X')
                ileSasiadow++;
            if(siatka[i][j+1] == 'X')
                ileSasiadow++;
            if(siatka[i][j-1] == 'X')
                ileSasiadow++;
            if(siatka[i-1][j+1] == 'X')
                ileSasiadow++;
            if(siatka[i-1][j] == 'X')
                ileSasiadow++;
            if(siatka[i-1][j-1] == 'X')
                ileSasiadow++;
           // cout<<i<<" "<<j<<" "<<ileSasiadow<<endl;

            if(siatka[i][j] == '.' && ileSasiadow == 3)
                tmp[i][j] = 'X';
            else if(siatka[i][j] == 'X' && ( ileSasiadow == 2 || ileSasiadow == 3))
                tmp[i][j] = 'X';
            else
                tmp[i][j] = '.';
        }

    }
    siatka = tmp;

}

void _fill()
{
    for(int k = 1; k<21; k++)
    {
        siatka[0][k] = siatka[12][k];
        siatka[13][k] = siatka[1][k];
    }
    for(int k = 1; k <13; k++)
    {
        siatka[k][0] = siatka[k][20];
        siatka[k][21] = siatka[k][1];
    }

    siatka[0][0] = siatka[12][20];
    siatka[0][21] = siatka[12][1];
    siatka[13][0] = siatka[1][12];
    siatka[13][21] = siatka[1][1];



}

void zad1()
{
    for(int i=0; i<37; i++)
    {
        ruch();
        _fill();

    }
    int ileSasiadow = 0,  i = 2,  j = 19;
            if(siatka[i+1][j-1] == 'X')
                ileSasiadow++;
            if(siatka[i+1][j] == 'X')
                ileSasiadow++;
            if(siatka[i+1][j+1] == 'X')
                ileSasiadow++;
            if(siatka[i][j+1] == 'X')
                ileSasiadow++;
            if(siatka[i][j-1] == 'X')
                ileSasiadow++;
            if(siatka[i-1][j+1] == 'X')
                ileSasiadow++;
            if(siatka[i-1][j] == 'X')
                ileSasiadow++;
            if(siatka[i-1][j-1] == 'X')
                ileSasiadow++;
    cout<<ileSasiadow<<endl;
    ofstream wyniki("wyniki.txt");
    wyniki<<"zad 5.1\n"<<ileSasiadow<<endl;
    wyniki.close();

}

void zad2()
{
    ruch();
    _fill();

    int licznik = 0;
    for(int i=1; i<13; i++)
    {
        for(int j = 1; j<21; j++)
        {
            if(siatka[i][j] == 'X')
                licznik++;
        }
    }
    ofstream wyniki("wyniki.txt", ios::app);
    wyniki<<"zad 5.2\n"<<licznik<<endl;
    wyniki.close();
}

void zad3()
{
    vector<vector<char> > prev;

    for(int i =0; i<100; i++)
    {
        prev = siatka;

        ruch();
        _fill();

        bool toSamo = true;
        int licznik = 0;

        for(int i=1; i<13; i++)
        {
            for(int j = 1; j<21; j++)
            {
                if(siatka[i][j] != prev[i][j])
                    toSamo = false;
                if(prev[i][j] == 'X')
                    licznik++;
            }
        }

        if(toSamo == true)
        {
            i = 100;
            break;
            ofstream wyniki("wyniki.txt", ios::app);
            wyniki<<"zad 5.3\n"<<"Pokolenie: "<<i+1<<"\nZywych: "<<licznik<<endl;
            wyniki.close();
            cout<<"found"<<endl;

        }


    }


}

int main()
{
    ifstream dane("gra.txt");

    for(int i =1; i<13; i++)
    {
        for(int j = 1; j<21; j++)
        {
            char a;
            dane>>a;
            siatka[i][j] = a;
        }
    }


  _fill();


    for(int i =0; i<14; i++)
    {
        for(int j =0; j<22; j++)
        {
            cout<<siatka[i][j]<<" ";
        }
        cout<<endl;
    }

        cout<<endl<<endl;
   // zad1();
   // zad2();
    zad3();



    return 0;
}
