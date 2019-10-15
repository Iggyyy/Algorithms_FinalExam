#include <iostream>

using namespace std;


int nwd(int a, int b)
{
   while(a != b)
   {
       if (a>b) a-=b;
       else b-=a;
   }
     return a;
}
int nww(int a, int b)
{
    return (a*b)/nwd(a,b);
}

int NWDrecurs(int a, int b)
{
    if(a > b) a = NWDrecurs(a-b, b);
    else if (a <b) a = NWDrecurs(a, b-a);
    else return a;
}

int NWDoptimized(int a, int b)
{
    while(b != 0)
    {
      int c = b;
      b = a % b;
      a = c;
    }
    return a;
}


int main()
{

    cout<<"NWW i NWD\nProsze podac a i b: "<<endl;
    int a,b;
    cin>>a>>b;
    cout<<"nwd: "<<nwd(a,b)<<endl;
    cout<<"nww: "<<nww(a,b)<<endl;
    cout<<"nwdRecursive: "<<NWDrecurs(a,b)<<endl;
    cout<<"nwdOptimized: "<<NWDoptimized(a,b)<<endl;



    return 0;
}
