#include <iostream>
#include <vector>

using namespace std;

void bubble_sort_ascending(vector<int> tablica)
{

    for(int i =0; i<tablica.size()-1; i++)
    {
        for(int j = 0; j<tablica.size()- i -1; j++)             //PAMIÊTAÆ O SKRÓCENIU O -1 oraz i
        {
            if(tablica[j] > tablica[j+1])
                swap(tablica[j], tablica[j+1]);
        }
    }
    for( auto i : tablica)
        cout<< i <<endl;
}

void bubble_sort_descending(vector<int> tablica)
{

    for(int i =0; i<tablica.size()-1; i++)
    {
        for(int j = 0; j<tablica.size()- i -1; j++)
        {
            if(tablica[j] < tablica[j+1])
                swap(tablica[j], tablica[j+1]);
        }

    }

    for( auto i : tablica)
        cout<< i <<endl;
}

int main()
{
    vector<int> tablica {1 ,2, 5, 5, 7, 1, 2, 19,3};

    bubble_sort_ascending(tablica);
    bubble_sort_descending(tablica);



    return 0;
}
