#include <iostream>
#include <vector>

using namespace std;



void selectionSort(vector<int> &tab)
{
    for(int i =0; i<tab.size(); i++)
    {
        int min_index = i;
        for(int j = i+1; j<tab.size(); j++)
        {
            if(tab[j] < tab[min_index])
                min_index = j;
        }

        swap(tab[i], tab[min_index]);

    }
}
int main()
{
    vector<int> inp;


    for(int i =0; i<20;i++)
    {
        inp.push_back(rand()%100);
    }
    for(int i: inp)
        cout<<i<<" ";
    cout<<endl;

    selectionSort(inp);

    for(int i: inp)
        cout<<i<<" ";

    return 0;
}
