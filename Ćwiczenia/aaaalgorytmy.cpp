#include <bits/stdc++.h>

using namespace std;

int binSearch(vector<int> &tab, int x, int l, int r)
{
	while(l<=r)
	{
		 int sr = (l+r)/2;

		if(tab[sr] > x)
			r = sr - 1;
		else if(tab[sr] < x)
			l = sr + 1;
        else
            return sr;
	}
	return -1;
}
void insertionSort(vector<int> &tab)
{
    for(int i = 1; i < tab.size(); i++)
    {
        int pom  = tab[i];
        int j = i-1;
        while(pom < tab[j] && j>=0)
        {
            tab[j+1] = tab[j];
            j--;
        }
        tab[j+1] = pom;
    }


}
void selectionSort(vector<int> &tab)
{

    for(int i =0; i <  tab.size(); i++)
    {
        int index = i;
        for(int j = i; j< tab.size(); j++)
        {
            if(tab[j] > tab[index])
                index = j;
        }

        swap(tab[i], tab[index]);
    }

}
void bubbleSort(vector<int> &tab)
{
    for(int i =0; i<tab.size(); i++)
    {
        for(int j = 0; j<tab.size()-1; j++)
        {
            if(tab[j] > tab[j+1])
                swap(tab[j], tab[j+1]);
        }
    }

}


int main()
{
	cout<<"Podaj liczbe szukana: ";
	int a; cin>>a;
	vector<int> tablica = {2,3,6,7,8,9,12,15,46,76,345,1223,6546546};

	cout<< "index w tablicy: "<<binSearch(tablica, a, 0, tablica.size()-1)<<endl;


    vector<int> tab = {3,5,2,6,7,4,3,234,6,45,64,6,3,24};
    insertionSort(tab);

    for(int i =0; i<tab.size(); i++)
    {
        cout<<tab[i]<<" ";
    }
    selectionSort(tab);
    cout<<endl;
    for(int i =0; i<tab.size(); i++)
    {
        cout<<tab[i]<<" ";
    }
     bubbleSort(tab);
    cout<<endl;
    for(int i =0; i<tab.size(); i++)
    {
        cout<<tab[i]<<" ";
    }


	return 0;
}
