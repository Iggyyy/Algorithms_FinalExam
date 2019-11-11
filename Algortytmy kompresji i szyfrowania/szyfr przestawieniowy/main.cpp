#include <bits/stdc++.h>
#include <vector>


using namespace std;

void kodowanie(char *napis)
{
    for(int i =0; i< strlen(napis)-1; i+=2)
    {
        swap(napis[i], napis[i+1]);

    }

}

bool czySpolgloska(char a)
{
    if(a != 'a' && a != 'e' && a != 'u' && a != 'y' && a!= 'o' && a!= 'ó' && a != 'i')
        return true;
    else
        return false;
}
void _kodowanie(char *napis)
{
	int dl = strlen(napis); //wyznaczenie liczby znaków

	//nale¿y zapamiêtaæ pozycjê pierwszej spó³g³oski
	bool f=1;	//czy dana spó³g³oska jest pierwsza
	int nr; 	//pozycja pierwszej spó³g³oski
	char first;	//przechowujemy spó³g³oskê do podmiany

	for(int i=0;i<dl;i++)
		{
			if(czySpolgloska(napis[i]))
			{
				if(f)	//jesli wczytana spó³g³oska jest pierwsza
				{		//to j¹ spamiêtujemy
					nr = i;
					first = napis[i];
					f = 0;
				}
				else //podmiana
				{
					char pom = napis[i];
					napis[i] = first;
					first = pom;
				}
			}

		}
		if(!f)
			napis[nr] = first;
}

void kodowanie_jeden(char *napis)
{
    bool first = false;
    int _first;
    int _index_first;

    bool _pom = false;
    int pom;
    int _swit;


    for(int i = 0; i< strlen(napis); i++)
    {
        if(first== false && czySpolgloska(napis[i]) == true)
            {
                _index_first = i;
                first = true;
                _first = napis[i];
            }
        if(czySpolgloska(napis[i]) == true)
        {
            if(_pom == false)
            {
                _pom = true;
                pom = napis[i];
            }
            else
            {
                napis[i] = pom;
                _swit = napis[i];
                _pom = false;
            }
        }



    }

    napis[_index_first] = pom;


}




int main()
{
    char a[256];
    cout<<"Podaj tekst do zakodowania przestawnie"<<endl;

    cin.getline(a, 256);

    kodowanie(a);

    cout<<"Zaszyfrowany: " <<a<<endl;

    kodowanie(a);

    cout<<"Odszyfrowany: "<<a<<endl;


    char b[256];
    cout<<"Podaj tekst do zakodowania przesuniêcie samog³osek o jedno w prawo"<<endl;

    cin.getline(b, 256);

    kodowanie_jeden(b);

    cout<<"Zaszyfrowany: " <<b<<endl;




    return 0;
}
