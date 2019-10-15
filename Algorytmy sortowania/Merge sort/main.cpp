#include <bits/stdc++.h>

using namespace std;

int *pom;


void _merge(int tab[], int lewy, int srodek, int prawy)
{
    //KOPIOWANIE LEWEJ I PRAWEJ DO TABLICY POMOCNICZEJ
    for(int i = lewy; i<=prawy; i++)
        pom[i] = tab[i];

    int i = lewy, j = srodek +1;

    //SCALANIE DWOCH PODTABLIC POMOCNICZYCH indexy j, i

    for(int k = lewy; k <= prawy; k++)
    {
        if(i<=srodek)
        {
            if(j<=prawy)
                {
                    if(pom[j] < pom[i])
                        tab[k] = pom[j++];
                    else
                        tab[k] = pom[i++];
                }
            else
                tab[k] = pom[i++];
        }
        else
            tab[k] = pom[j++];
    }

}


void merge_sort(int tab[], int lewy, int prawy)
{

    //JEZELI JEST 1 ELEMENT ALBO ZLE DANE
    if(prawy<=lewy) return;
    //SRODEK
    int srodek = (prawy + lewy )/2;
    //DZIELIMY NA CZESC PRAWA I LEWA
    merge_sort(tab,srodek+1, prawy);
    merge_sort(tab, lewy, srodek);

    _merge(tab, lewy, srodek, prawy);

}


int main()
{
    int *tab, n;
    n = 50;
    tab = new int[n];
    pom = new int[n];

    srand(time(0));
    for(int i =0; i<50; i++)
        tab[i] = rand()%100+1;








    merge_sort(tab,0,n-1);

    for(int i = 0; i<n; i++)
        cout<<tab[i]<<",";


    return 0;
}
