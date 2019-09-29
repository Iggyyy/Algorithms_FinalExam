#include <iostream>

using namespace std;


double f(double x)
{
    //FUNKCJA OKREŒLONA WZOREM: f(x) = x^3 - 3x^2 + 2x -6
    return x*(x*(x-3)+2)-6;

}

double miejsceZero(double a, double b, double epsilon)
{
    if(f(a) == 0.0) return a;
    if(f(b) == 0.0) return b;

    double srodek;

    while( b- a > epsilon)
    {
        srodek = (a+b)/2;

        if(f(srodek) == 0.0) return srodek;

        if( f(a) *  f(srodek) < 0)
            b = srodek;
        else
            a=srodek;

    }

    return (a+b)/2;

}



int main()
{
    double a,b,e;
    cout<<"Prosze podac przedzial a,b oraz dokladnosc"<<endl;
    cin>>a>>b>>e;

    cout<<"Miejsce zerowe to: "<<miejsceZero(a,b,e);



    return 0;
}
