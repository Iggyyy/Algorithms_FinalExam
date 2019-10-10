#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;


int binarySearch(int x, int l, int r, vector<int> tablica)
{

    while(l<=r)
    {
      int m = l + (r-l) /2;

      if(tablica[m] == x) return m;

      if (tablica[m] < x) l = m + 1;
      else r = m-1;


    }

    return -1;

}
int binarSearch(int x, int l, int r, vector<int> tab)
{

    while(l<=r)
    {
        int m = l +(r-l) /2 ;

        if(tab[m] == x) return m;
        if(tab[m] < x) l = m +1;
        else r = m -1;

    }
    return -1;
}


bool binaryPractice(int x, int l, int r, vector<int> tab)
{

    while(l<r)
    {
            int mid = l + (r-l) /2;

            if(x>tab[mid])
                l = mid +1;
            else if (x<tab[mid])
                r = mid - 1;
            else
                return true;


    }
    return false;
}



int main()
{
    srand(time(NULL));
    vector<int> vect;
    for(int i = 0; i<20; i++)
    {
        vect.push_back(rand()%100 +1);
    }

    sort(vect.begin(), vect.end());

    for(int i : vect)
        cout<<i<<endl;


    cout<<"WprowadŸ szukana liczbe"<<endl;
    int a;
    cin>>a;
    cout<<"index in array: "<<binarySearch(a, 0, vect.size()-1, vect)<<'\n';

    cout<<"index in array: "<<binarySearch(a, 0, vect.size()-1, vect)<<'\n';









    return 0;
}
