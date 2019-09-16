#include <iostream>

using namespace std;


int nwd(int a, int b)
{
    cout<<a<<" "<<b<<endl;
   if (a > b) a = nwd(a-b, b);
   else if (b>a) b = nwd(a, b-a);
   else
   {
       return a;
       cout<<a<<endl;
   }
cout<<a<<" - "<<b<<endl;

     return a;
}


int main()
{

    cout<<"NWW i NWD\nProszê podaæ a i b: "<<endl;
    int a,b;
    cin>>a>>b;
    cout<<"nwd: "<<nwd(a,b)<<endl;

    return 0;
}
