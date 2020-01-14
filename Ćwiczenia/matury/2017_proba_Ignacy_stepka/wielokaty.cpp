#include <bits/stdc++.h>

using namespace std;
double czw = 0, spczw = 0;

double poleWielo(int a, vector<int> &px, vector<int> &py)
{
    double sum = 0;
    for(int i = 1; i<a-1; i++)
    {
        double x1 = px[0] - px[i], y1 = py[0] - py[1], x2 = px[0] - px[i+1], y2 = py[0] - py[i+1];
        sum+= fabs(x1*y2 - x2*y1)/2;

        cout<<sum<<endl;
    }
    if(a == 4)
    {
        czw++;
        spczw+=sum;
    }

    return sum;
}
double ileKrat(int a, vector<int> &px, vector<int> &py)
{
    int licz = 0;
    for(int i = 0; i<a; i++)
    {

    }


    return licz;
}



int main()
{
        fstream plik;
        plik.open("ddd.txt", ios::in);
        int troj = 0, piec = 0;
        double pmax = 0, pmin = 9999;
        double odl = 0;

        while(!plik.eof())
        {
            int a;
            plik>>a;
            //cout<<a<<endl;

            vector<int> px;
            vector<int> py;

            for(int i =0; i<a; i++)
            {
                int x,y;
                plik>>x>>y;
                px.push_back(x);
                py.push_back(y);
                //cout<<px[i]<<" "<<py[i]<<endl;


                 double odleg = sqrt( x*x + y*y);
                 if(odleg > odl)
                    odl = odleg;

            }
            if (a == 3)
            {
                troj++;
            }
            else if (a == 5)
            {
                piec++;
            }

            double pole = poleWielo(a,px,py);
            if(pole > pmax)
                pmax = pole;
            if(pole < pmin)
                pmin = pole;


        }
        cout<<"zad1:\nTrojkatow: "<<troj<<" pieciokatow: "<<piec<<endl;
        cout<<"zad2:\nPole max: "<<pmax<<" Pole min: "<<pmin<<endl;
        cout<<"zad3:\nNajwiekszy promien: "<<odl<<endl;
        cout<<"zad5:\nSrednie pole czworokata: "<<spczw/czw<<endl;
        plik.close();
}
