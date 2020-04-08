#include <bits/stdc++.h>

using namespace std;
vector<double> A,B,R;



int wCwiartce(double x, double y, double r)
{
    int ret = -1;
    if(x < 0)
    {

        if(y > 0)
        {
            if(x + r < 0 && y - r > 0)
                ret = 2;
            else ret = 0;
        }
        if(y < 0)
        {
            if(x + r < 0 && y+r < 0)
                ret = 3;
            else ret =0;
        }
    }
    else if(x > 0)
    {

        if(y > 0)
        {
            if( x - r > 0 && y - r > 0)
                ret = 1;
            else ret = 0;
        }
        else if(y < 0)
        {
            if(x -r > 0 && y +r < 0)
                ret = 4;
            else ret = 0;
        }

    }
    else
        {
            ret = 0;
        }
    return ret;


}

bool czyLust(double x, double y, double r, double xb, double yb, double rb)
{
    if(r != rb)
        return false;

    if( (x == xb && y == -yb)  || (x == -xb && y == yb) || (x == -xb && y == -yb) )
        return true;
    else return false;
}


void zad1()
{

    vector<int> cwiartki(5, 0);
    for(int i = 0; i< A.size(); i++)
    {

        int cw = wCwiartce(A[i], B[i], R[i]);
        //cout<<cw;
        cwiartki[cw]++;

    }
    cout<<"ZAD1:"<<endl;
    for(int i = 1; i< 5; i++)
        cout<<cwiartki[i]<< " ";
    cout<<cwiartki[0]<<endl;


}

void zad2()
{


}

void zad3()
{

}


int main()
{
    ifstream dane("okregi.txt");
    while(!dane.eof())
    {
        //cout<<"XD"<<endl;
        double ax,by,rr;
        dane>>ax>>by>>rr;
        A.push_back(ax);
        B.push_back(by);
        R.push_back(rr);
        //cout<<ax<<endl;
    }
    zad1();
    zad2();

    dane.close();
    return 0;
}
