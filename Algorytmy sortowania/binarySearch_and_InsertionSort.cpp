#include <vector>
#include <iostream>

using namespace std;


bool binarySearch(int x, int l, int r, vector<int> tab)
{
    while (l<=r)
    {
        int mid = l + (r-l) /2;

        if(tab[mid] < x)
            l = mid+1;
        else if(tab[mid] > x)
            r = mid-1;
        else
            return true;
    }
    return false;
}

void sortArray(vector<int> &tab)
{
    int pom, j;

    for(int i = 1; i<tab.size(); i++)
    {
        pom = tab[i];
        j = i -1;
        while(j>=0 && tab[j] > pom)
        {
            tab[j+1] = tab[j];
            j--;
        }
        tab[j+1] = pom;

    }


}



int main()
{
    cout<<"Do wyszukania: "<<endl;
    int a;
    cin>>a;

    vector<int> tablica = {7,1,2,5,3,4,5,6,7,8,9};

    //INSERTION SORT
    sortArray(tablica);

    for(int i : tablica)
        cout<<i;

    cout<< (binarySearch(a, 0, tablica.size()-1, tablica ) == true ? "Znaleziono" : "Nie znaleziono")<<endl;

    return 0;
}
