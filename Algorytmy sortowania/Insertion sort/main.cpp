#include <iostream>
#include <vector>

using namespace std;

void insertion_sort(int siz, vector<int> &tab)
{

    int pom, j;

    for(int i =1; i<siz; i++)
    {
        pom = tab[i];
        j = i-1;

        while(j>=0 && tab[j] > pom)
        {
            tab[j+1] = tab[j];
            j--;
        }
        tab[j+1] = pom;
    }


    cout<<"Sorted"<<endl;
}




int main()
{
        vector<int> tab{3,4,1,2,6,8,3,9,5,7,3,2,1,12,64,5,0};
        for(auto num : tab)
            cout<<num<<" ";
        cout<<endl;

        insertion_sort(tab.size(), tab);


        for(auto num : tab)
            cout<<num<<" ";
        cout<<endl;

    return 0;
}
