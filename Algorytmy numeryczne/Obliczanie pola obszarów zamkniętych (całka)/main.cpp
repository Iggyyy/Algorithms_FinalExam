#include <iostream>

using namespace std;


double f(double x)
{
    return x*x+x+2;
}



double pole(int a, int b, int n)
{
    double suma = 0;
    double x= (b-a)/(double)n;
    double srodek = a + (b-a)/(2.0 *n);

    for (int i =0;i<n;i++)
    {
        suma+=f(srodek);
        srodek+=x;

    }
    return suma*x;
}




int main()
{

    int a,b,c;
    cout<<"Podaj a, b i c jako liczbe prostokatow"<<endl;
    cin>>a>>b>>c;
    cout<<"pole; "<<pole(a,b,c)<<endl;



    return 0;
}
