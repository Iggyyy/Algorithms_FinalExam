#include <iostream>

using namespace std;

long long factorial_recursion(long long base)
{
    if(base !=1) return base*factorial_recursion(base-1);
    else
        return base;
}

long long power_recursive(long long base, long long upto)
{
    if(upto == 0) return 1;
    else{
        return base*power_recursive(base, upto-1);
    }

}

int natural_sum(int n)
{
    if(n > 1) return n + natural_sum(n -1);
    else return 1;
}



int main()
{
    cout<<"Factorial: "<<endl;
    int a;
    cin>>a;
    cout<<factorial_recursion(a)<< '\n';

    cout<<"Power (base and power index): "<<endl;
    int b, p;
    cin>>b>>p;
    cout<<power_recursive(b,p)<<'\n';

    cout<<"Natural number sum: "<<endl;
    int c;
    cin>>c;
    cout<<natural_sum(c)<<'\n';


    return 0;
}
