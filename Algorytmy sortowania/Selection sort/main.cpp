#include <iostream>
#include <vector>
using namespace std;



void selection_sort(vector<int> &tab, int n)
{
    for(int i =0; i<=n-1; i++)
    {
        int index_min = i;

        for(int j = i+1; j <n; j++)
        {
            if(tab[j] < tab[index_min])
                index_min = j;
        }
        swap(tab[i], tab[index_min]);
    }


}


int main()
{
    vector<int> tab;

    for (int i =0 ;i<50; i++)
        tab.push_back(rand()%101);


    int n = tab.size();
    selection_sort(tab, n);

    for(int i: tab)
        cout<<i<<endl;
    return 0;
}
