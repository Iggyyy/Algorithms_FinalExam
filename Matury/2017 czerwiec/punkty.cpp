#include <bits/stdc++.h>


using namespace std;
ofstream wyniki;

void erastos(vector<int> &pierwsze, int n)
{
    pierwsze[0] = 1;
    pierwsze[1] = 1;

    for(int i = 2; i*i < n+1; i++)
    {

        if(pierwsze[i] == 0)
        {
            for(int j =i+i; j<n+1; j+=i)
            {
                pierwsze[j] = 1;
            }
        }

    }

}


void zad4_1()
{
    int n = 10000;
    vector<int> pierwsze(n+1, 0);
    erastos(pierwsze, n);

    fstream dane("punkty.txt");
    int licznik = 0;
    while(!dane.eof())
    {
        int _x, _y;
        dane>>_x>>_y;
       if(pierwsze[_x] == 0 && pierwsze[_y] == 0)
        licznik++;
    }
    wyniki<<"ZADANIE 4.1\n"<<licznik<<endl;
    dane.close();

}

void zad4_2()
{
    ifstream dane("punkty.txt");
    int licznik = 0;
    while(!dane.eof())
    {
        int x,y;
        dane>>x>>y;

        vector<int> xcyfry(10,0), ycyfry(10,0);

        while(x > 0)
        {
            int p = x%10;
            xcyfry[p]++;
            x/=10;
        }
        while(y>0)
        {
            int p = y%10;
            ycyfry[p]++;
            y/=10;
        }

        bool podobne = true;
        for(int i =0; i<10; i++)
        {
            if(xcyfry[i] >0)
            {
                if(ycyfry[i]==0)
                    podobne = false;
            }
            if(ycyfry[i] >0)
            {
                if(xcyfry[i]==0)
                    podobne = false;
            }
        }
        if(podobne == true)
            licznik++;


    }

    wyniki<<"ZADANIE 4.2:\n"<<licznik<<endl;


    dane.close();
}

void zad4_3()
{
    vector<int> X, Y;
    ifstream dane("punkty.txt");
    while(!dane.eof())
    {
        int _x, _y;
        dane>>_x>>_y;
        X.push_back(_x);
        Y.push_back(_y);
    }
    int maks = 0, a, b;

    for(int i =0; i< X.size(); i++)
    {
        for(int j = i+1; j<X.size(); j++)
        {
            int odl = sqrt(pow(X[i] - X[j], 2) + pow(Y[i] - Y[j], 2));

            if(odl > maks)
            {
                maks = odl;
                a = i;
                b = j;
            }
        }
    }
    wyniki<<"ZAD 4_3:\n";
    wyniki<<X[a]<<" "<<Y[a]<<endl;
    wyniki<<X[b]<<" "<<Y[b]<<endl;

    dane.close();
}

void zad4_4()
{
    int wew = 0, zew = 0, bok = 0;
    ifstream dane("punkty.txt");
    while(!dane.eof())
    {
        int x,y;
        dane>>x>>y;

        if((y == 5000 || y == -5000) && x >=-5000 && x<=5000)
            bok++;
        else if(y < 5000 && y > -5000 && x >-5000 && x<5000)
            wew++;
        else
            zew++;
    }

    wyniki<<"ZADANIE 4.4:\na) "<<wew<<endl;
    wyniki<<"b) "<<bok<<endl;
    wyniki<<"c) "<<zew<<endl;
    dane.close();

}

int main()
{
    wyniki.open("wyniki4.txt");
    zad4_1();
    zad4_2();
    zad4_3();
    zad4_4();
    cout<<"utworzono plik wynikowy"<<endl;
    return 0;
}
