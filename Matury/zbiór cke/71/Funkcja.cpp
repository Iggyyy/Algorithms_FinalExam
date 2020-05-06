#include <bits/stdc++.h>

using namespace std;
vector<vector<float> >funkcje;


float horner(vector<float> &wsp, int pot, float x)
{
    if(pot == 0)
        return wsp[0];
    return x * horner(wsp, pot-1, x) + wsp[pot];

}
void zad1()
{
    cout<<"ZAD 1:"<<endl;



    cout<<horner(funkcje[1], funkcje[1].size()-1, 1.5f)<<endl;


}
void zad2()
{
    float step = 0.001;
    float maxw = 0;
    float index = 0;


    for(float i = 0; i<5; i+=step)
    {
        float x = horner(funkcje[(int)i], 3, i);
        if(maxw<x)
        {
            maxw= x;
            index = i;
        }


    }


    cout<<"ZAD2\nMax wart "<<maxw<<" x = "<<index<<endl;
}




void zad3()
{
    float prec = 0.01;
    vector<int> znaki;


    for(float i = 0; i< 5; i+=prec)
    {
        if(horner(funkcje[i], 3, i) > 0) znaki.push_back(1);
        else znaki.push_back(0);
    }

    for(float i = 0; i< znaki.size()-1; i++)
    {
        if(znaki[i] != znaki[i+1])//PRZEDZIA£Y
        {
            float najbliz = 1000;
            float dokl = 0.000001;
            float index = 0;
           // cout<<i/100<<" "<<(i+1)/100<<endl;

            for(float k = i/100; k<(i+1)/100; k+=dokl)
            {
                float odl = abs(0-horner(funkcje[(int)k], 3, k));
                if(odl < najbliz)
                {
                    najbliz = odl;
                    index = k;
                }

            }

            cout<<setprecision(6)<<"x0 = "<< index<<" "<<najbliz<<endl;
        }
    }

}





int main()
{
    ifstream plik("funkcja.txt");
    while(!plik.eof())
    {
        vector<float> tmp;
        for(int i = 0; i<4; i++)
        {
            float x;
            plik>>x;
            tmp.push_back(x);
            cout<<x<<" ";
        }
        cout<<endl;
        reverse(tmp.begin(), tmp.end());
        funkcje.push_back(tmp);
    }
    plik.close();
    cout<<"Wczytano dane"<<endl;


    zad1();
    zad2();
    zad3();
    return 0;
}
