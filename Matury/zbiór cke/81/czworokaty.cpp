#include <bits/stdc++.h>
using namespace std;
vector< vector<int> >wierzcholki(100, vector<int>(6, 0));
vector< vector<int> >wspolrzedneTR(100, vector<int>(6, 0));



void readData()
{
    ifstream dane("wspolrzedne.txt");
    for(int i =0; i<100; i++)
    {
        for(int j =0; j<6; j++)
        {
            int a; dane>>a;
            wierzcholki[i][j] = a;
            //cout<<a;
        }
    }
    dane.close();

     ifstream plik("wspolrzedneTR.txt");
    for(int i =0; i<100; i++)
    {
        for(int j =0; j<6; j++)
        {
            int a; plik>>a;
            wspolrzedneTR[i][j] = a;
            //cout<<a;
        }
    }
    plik.close();
}
void zad1()
{
    int licznik = 0;
    for(int i =0; i<100; i++)
    {
        bool good = true;

        for(int j =0; j<6; j+=2)
        {
           if(wierzcholki[i][j] <= 0 || wierzcholki[i][j+1] <= 0)
            good = false;

        }
        if(good) licznik++;
    }
    cout<<"Zad1:\nSpelniajacych warunki: "<<licznik<<endl;
}

double odleg(int xa, int ya, int xb, int yb)
{
    double odl = sqrt( pow(xb-xa, 2) + pow(yb-ya,2));
    return odl;
}
double odlegPOW(int xa, int ya, int xb, int yb)
{
    double odl = pow(xb-xa, 2) + pow(yb-ya,2);
    //cout<<odl<<endl;
    return odl;
}
void zad3()
{
    double najw = 0, index;
    for(int i =0; i<100; i++)
    {
        double odl = 0;
        odl += odlegPOW(wspolrzedneTR[i][0], wspolrzedneTR[i][1], wspolrzedneTR[i][2], wspolrzedneTR[i][3]);
        odl += odlegPOW(wspolrzedneTR[i][0], wspolrzedneTR[i][1], wspolrzedneTR[i][4], wspolrzedneTR[i][5]);
        odl += odlegPOW(wspolrzedneTR[i][4], wspolrzedneTR[i][5], wspolrzedneTR[i][2], wspolrzedneTR[i][3]);
        if(odl > najw)
        {
            najw = odl;
            index = i;
        }

    }


   cout<<"ZAD3:\n "<<wspolrzedneTR[index][0]<<" "<<wspolrzedneTR[index][1]<<" "<<wspolrzedneTR[index][2]<<
   " "<<wspolrzedneTR[index][3]<<" "<<wspolrzedneTR[index][4]<<" "<<wspolrzedneTR[index][5]<<endl<<"Obwod: "<<setprecision(5)<<sqrt(najw)<<endl;



}

void zad4()
{
    int licznik = 0;

    for(int i =0; i<100; i++)
    {

        double bok1 = odlegPOW(wspolrzedneTR[i][0], wspolrzedneTR[i][1], wspolrzedneTR[i][2], wspolrzedneTR[i][3]);
        double bok2 = odlegPOW(wspolrzedneTR[i][0], wspolrzedneTR[i][1], wspolrzedneTR[i][4], wspolrzedneTR[i][5]);
        double bok3 = odlegPOW(wspolrzedneTR[i][4], wspolrzedneTR[i][5], wspolrzedneTR[i][2], wspolrzedneTR[i][3]);
        //cout<<bok1<<" "<<bok2<<" "<<bok3<<endl;
       if(bok1 + bok2 == bok3 || bok2 + bok3 == bok1 || bok3 + bok1 == bok2)
            licznik++;


    }
    cout<<"ZAD4:\n"<<licznik<<endl;
}
void zad2()
{
    int licznik = 0;
     for(int i =0; i<100; i++)
    {
        int vectACx = wierzcholki[i][4] - wierzcholki[i][0];
        int vectACy = wierzcholki[i][5] - wierzcholki[i][1];
        int vectABx = wierzcholki[i][2] - wierzcholki[i][0];
        int vectABy = wierzcholki[i][3] - wierzcholki[i][1];

        if(vectABx * vectACy - vectACx * vectABy == 0) licznik++;

    }
    cout<<"ZAD2:\n"<<licznik<<endl;


}
void zad5()
{
    int licznik = 0;
    for(int i =0; i<100; i++)
    {
        int vectBCx = wspolrzedneTR[i][4] - wspolrzedneTR[i][2];
        int vectBCy = wspolrzedneTR[i][5] - wspolrzedneTR[i][3];

        int Dx = wspolrzedneTR[i][0] + vectBCx;
        int Dy = wspolrzedneTR[i][1] + vectBCy;

        if(Dy == Dx) licznik++;
    }
    cout<<"ZAD5:\nIle: "<<licznik<<endl;
}


int main()
{
    readData();
    zad1();
    zad2();
    zad3();
    zad4();
    zad5();
    return 0;
}
