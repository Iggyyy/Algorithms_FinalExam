#include <bits/stdc++.h>
using namespace std;


vector<vector<char> > siatka(12, vector<char>(20,0));



void ruch()
{
    cout<<endl;
    vector<vector<char> > tmp;
    tmp = siatka;

    for(int i =0 ;i <12; i++)
        {
            for(int j =0; j<20; j++)
            {
                 int ileSasiadow = 0;

                for(int k = -1; k<=1; k++)
                {
                    for(int m =-1; m<=1; m++)
                    {
                        int r = ((i+k)%12+12)%12;
                        int c = ((j+m)%20+20)%20;
                        if(siatka[r][c] == 'X')
                            ileSasiadow++;
                    }
                }

                if(siatka[i][j] == 'X' && ( ileSasiadow == 2 || ileSasiadow == 3))
                    tmp[i][j] = 'X';
                else if(siatka[i][j] == '.' && ileSasiadow == 3)
                    tmp[i][j] = 'X';
                else
                    tmp[i][j] = '.';

            }
        }



    siatka = tmp;
    for(int i =0 ;i <12; i++)
        {
            for(int j =0; j<20; j++)
            {
                cout<<siatka[i][j];
            }
            cout<<endl;
        }

}



void zad1()
{
    int ileSasiadow = 0;

    for(int i =0; i<10; i++)
    {
        ruch();
    }





    cout<<ileSasiadow<<endl;
    ofstream wyniki("wyniki.txt");
    wyniki<<"zad 5.1\n"<<ileSasiadow<<endl;
    wyniki.close();

}


int main()
{
    ifstream dane("gra.txt");

    for(int i =0; i<12; i++)
    {
        for(int j = 0; j<20; j++)
        {
            char a;
            dane>>a;
            siatka[i][j] = a;
            cout<<a;
        }
    cout<<endl;
    }
    cout<<"Wczytano"<<endl;



   zad1();
   // zad2();
    //zad3();



    return 0;
}
