#include <bits/stdc++.h>
using namespace std;

int NWD(int a, int b)
{
	while(b!=0)
	{
	int pom = b;
	b = a%b;
	a = pom;
	}
	
	return a;
}


int main()
{
	int i = 0, n =5;
	while(i<n-1)
	{
		int j = i+1;
		
		while(j<n)
		{
			if(NWD(4,3)==1)
			cout<<"sss"<<endl;
			j+=1;
		}
		i+=1;
	}
	
	
	cout<<NWD(4,12);
	
}
