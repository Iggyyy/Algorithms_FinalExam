#include <iostream>
#include <vector>



using namespace std;

int nwd(int a, int b)
{
    while(b!=0)
    {
        int tmp = b;
        b = a % b ;
        a = tmp;
    }
    return a;
}

int nww(int a, int b)
{
    return (a*b)/nwd(a,b);
}

int binSearch(vector<int> &tab, int l, int r, int x)
{
    while(l<=r)
    {
        int sr = l + (r-l)/2;
        if(tab[sr] == x)
            return sr;
        else if(tab[sr] < x)
            l = sr+1;
        else if(tab[sr] > x)
            r = sr -1;
    }
    return -1;
}

void selectionSortAscend(vector<int> &tab)
{

    for(int i =0; i< tab.size(); i++)
    {
        int mini = tab[i], index = i;

        for(int j = i+1; j<tab.size(); j++)
        {
            if(tab[j] < mini)
            {
                mini = tab[j];
                index = j;
            }

        }
        swap(tab[i], tab[index]);
    }

}

void selectionSortDescend(vector<int> &tab)
{
    for(int i =0; i< tab.size(); i++)
    {
        int _max = tab[i], index = i;

        for(int j = i+1; j<tab.size(); j++)
        {
            if(tab[j] > _max)
            {
                _max = tab[j];
                index = j;
            }

        }
        swap(tab[i], tab[index]);
    }
}

void insertionSortAsc(vector<int> &tab)
{
    for(int i =1; i<tab.size(); i++)
    {
        int tmp = tab[i];
        int j = i-1;

        while(j>=0 && tab[j] > tmp)
        {
                tab[j+1] = tab[j];
                j = j-1;
        }
        tab[j+1] = tmp;

    }
}

void insertionSortDesc(vector<int> &tab)
{
    for(int i =1; i< tab.size(); i++)
    {
        int tmp = tab[i];
        int j  = i - 1;
        while(j>=0 && tmp > tab[j])
        {
            tab[j+1] = tab[j];
            j = j-1;
        }
        tab[j+1] = tmp;
    }
}

vector<int> mergeTwoArr(vector<int> first, vector<int> second)
{

}


int main()
{
    cout<<"NWD: "<<nwd(12,2)<<"\n";
    cout<<"NWW: "<<nww(12,2)<<"\n";

    vector<int> lista = {1,2,3,4,5,5,7,8,9,9};
    int s = lista.size();

    cout<<"BinSearch index of searched number: "<<binSearch(lista,0,lista.size()-1,8)<<endl;

    vector<int> toSort = {3,5,2,7,3,4,7,8,21,65,2,12,75,3,5,6};
    cout<<"Before sort: ";
    for(int i : toSort)
        cout<<i<<" ";

    selectionSortAscend(toSort);
    cout<<"\nAfter selection sort (ascending): ";
    for(int i : toSort)
        cout<<i<<" ";

    selectionSortDescend(toSort);
    cout<<"\nAfter selection sort (descending): ";
    for(int i : toSort)
        cout<<i<<" ";

    insertionSortAsc(toSort);
    cout<<"\nAfter insertion sort (ascending): ";
    for(int i : toSort)
        cout<<i<<" ";

    insertionSortDesc(toSort);
    cout<<"\nAfter insertion sort (descending): ";
    for(int i : toSort)
        cout<<i<<" ";


    return 0;
}
