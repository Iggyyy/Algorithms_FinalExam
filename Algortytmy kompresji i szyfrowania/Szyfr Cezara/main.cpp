#include <iostream>
#include <string.h>

using namespace std;


void cezar(char *tab, int base)
{
    if(base >= 26 || base <= -26)
        return;


    if(base >=0)
    {
        for(int i =0; i<strlen(tab); i++)
        {
            if(tab[i] + base <= 'Z')
                tab[i] += base;
            else
                tab[i] += base - 26;
        }

    }
    else
    {
        for(int i =0; i<strlen(tab); i++)
        {
            if(tab[i] +  base >= 'A')
                tab[i] += base;
            else
                tab[i] = 26 + tab[i] + base ;
        }

    }


}


int main()
{
    char ciag[256];
    cout << "Podaj ciag znaków do zaszyfrowania" << endl;
    cin.getline(ciag, 256);
    cout<<"Podaj o ile znakow ma byc przesuniecie"<<endl;
    int b;
    cin>>b;


    cezar(ciag, b);

    cout<<"zaszyfrowany: "<<ciag<<endl;

    cezar(ciag, -b);

    cout<<"odszyfrowany: "<<ciag<<endl;





    return 0;
}
