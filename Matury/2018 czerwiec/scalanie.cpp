#include <bits/stdc++.h>

using namespace std;



void zad1()
{

        ifstream plik1("dane1.txt");
        ifstream plik2("dane2.txt");

        int licznik = 0;

        for(int i=0; i<1000; i++)
        {
            for(int j = 0; j<10; j++)
            {
                int a1, a2;
                plik1>>a1;
                plik2>>a2;

                if(j == 9)
                {
                    if(a1 == a2)
                        licznik++;
                }


            }
        }

        cout<<licznik<<endl;
        ofstream wyniki("wyniki4.txt");
        wyniki<<"zad 4.1\n"<<licznik<<endl;

    plik1.close();
    plik2.close();
    wyniki.close();
}

void zad2()
{
     ifstream plik1("dane1.txt");
        ifstream plik2("dane2.txt");

        int licznik = 0;

        for(int i=0; i<1000; i++)
        {
            int parz = 0, nparz = 0, _parz = 0, _nparz =0;
            for(int j = 0; j<10; j++)
            {
                int a1, a2;
                plik1>>a1;
                plik2>>a2;
            if(a1 != 0)
               {
                if(a1%2 == 0)
                    parz++;
                else if (a1 % 2 == 1)
                    nparz++;
               }
            if(a2 != 0)
            {
                if(a2 %2 == 0)
                    _parz++;
                else if(a2 %2 == 1)
                    _nparz++;
            }

            }
            if(parz == _parz && nparz == _nparz && parz ==5 && nparz == 5)
               {
                 licznik++;

               }
        }

        cout<<licznik<<endl;
        ofstream wyniki("wyniki4.txt", ios::app);
        wyniki<<"zad 4.2\n"<<licznik<<endl;

    plik1.close();
    plik2.close();
    wyniki.close();

}

void zad3()
{
      ifstream plik1("dane1.txt");
      ifstream plik2("dane2.txt");

        int licznik = 0;
        vector<int> numery;

        for(int i=0; i<1000; i++)
        {
            vector<int> tab1(101, 0);
            vector<int> tab2(101, 0);

            for(int j = 0; j<10; j++)
            {
                int a1, a2;
                plik1>>a1;
                plik2>>a2;

                tab1[a1]++;
                tab2[a2]++;

            }
            //cout<<"Wczytano"<<endl;

            bool teSame = true;
            for(int k = 0; k< 101; k++)
            {
                if( (tab1[k] != 0 && tab2[k] != 0) || (tab1[k] == 0 && tab2[k] == 0) )
                {

                }
                else
                 {

                 teSame = false;
                 }
            }
            //cout<<"sprawdzono"<<endl;

            if (teSame != false)
            {
                licznik ++;
                numery.push_back(i);
            }
           // cout<<"zliczono"<<endl;
        }

        cout<<licznik<<endl;
        ofstream wyniki("wyniki4.txt", ios::app);
        wyniki<<"zad 4.3\nPar: "<<licznik<<endl;
        wyniki<<"Numery:"<<endl;
        for(int i =0; i<numery.size(); i++)
        {
            wyniki<<numery[i]<<" ";
        }

    plik1.close();
    plik2.close();
    wyniki.close();
}

void zad4()
{
        ifstream plik1("przyklad1.txt");
        ifstream plik2("przyklad2.txt");

        int licznik = 0;

        for(int i=0; i<5; i++)
        {
            vector<int> first;
            vector<int> second;
            for(int j = 0; j<10; j++)
            {
                int a1, a2;
                plik1>>a1;
                plik2>>a2;
                first.push_back(a1);
                second.push_back(a2);
            }

            vector<int> third;
            int f = 0, s = 0;
            for(int k=0; k < 20; k++)
            {
                if(first[f] >= second[s] && s < 10 && f < 10)
                {
                    third.push_back(first[f]);
                    f++;
                }
                else if(second[s] >= first[f] && s < 10 && f < 10)
                {
                    third.push_back(second[s]);
                    s++;
                }
                else if (s >= 10 && f <10)
                {
                    third.push_back(first[f]);
                    f++;
                }
                else
                {
                    third.push_back(second[s]);
                    s++;
                }
            }

        for(int k = 0; k< 20; k++)
        {
            cout<<third[k]<<" ";
        }

        cout<<endl;
        }

        cout<<licznik<<endl;
        ofstream wyniki("wyniki4.txt");
        wyniki<<"zad 4.4\n"<<endl;

    plik1.close();
    plik2.close();
    wyniki.close();
}


int main()
{
    cout<<"zad 4.1 \n";
    zad1();
    cout<<"zad 4.2 \n";
    zad2();
    cout<<"zad 4.3 \n";
    zad3();
    cout<<"zad 4.4 \n";
    zad4();

    return 0;
}
