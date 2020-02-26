#include <iostream>
#include <vector>

using namespace std;

int licznik = 0;

long long  silnia(long long x)
{
	if(x == 1)
		return 1;
	return x*silnia(x-1);
}

int fibonacci(int n)
{
	licznik++;
	
	if(n == 1 || n==2)
		return 1;
	
	return fibonacci(n-2) + fibonacci(n-1);
}

int fib_iter(int n)
{
	vector<int> fibo;
	fibo.push_back(0);
	fibo.push_back(1);
	fibo.push_back(1);
	
	for(int i = 3; i<=n; i++)
	{
		fibo.push_back(fibo[i-1] + fibo[i-2]);
	}
	return fibo[n];
}

int potega(int n, int pot)
{
	cout<<n;
	if(pot == 1)
		return n;	
	return potega(n, pot-1) * n; 
}




int main()
{
	int n = 20, m =4;
	cout<<"Silnia "<<n<<": "<<silnia(n)<<endl;
	cout<<"Fibonacci "<<n<<": "<<fibonacci(n)<<endl;
	cout<<"Fibonacci "<<n<<": "<<fib_iter(n)<<endl;
	cout<<"Liczba wywolan rekur: "<<licznik<<endl;
	cout<<"Potega "<<n<<" do "<<m<<": "<<potega(n,m)<<endl;
	
	return 0;
}

