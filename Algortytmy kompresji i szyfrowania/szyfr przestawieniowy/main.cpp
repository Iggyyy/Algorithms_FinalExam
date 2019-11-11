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
    if(a != 'a' && a != 'e' && a != 'u' && a != 'y' && a!= 'o' && a!= '�' && a != 'i')
        return true;
    else
        return false;
}
void _kodowanie(char *napis)
{
	int dl = strlen(napis); //wyznaczenie liczby znak�w

	//nale�y zapami�ta� pozycj� pierwszej sp�g�oski
	bool f=1;	//czy dana sp�g�oska jest pierwsza
	int nr; 	//pozycja pierwszej sp�g�oski
	char first;	//przechowujemy sp�g�osk� do podmiany

	for(int i=0;i<dl;i++)
		{
			if(czySpolgloska(napis[i]))
			{
				if(f)	//jesli wczytana sp�g�oska jest pierwsza
				{		//to j� spami�tujemy
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
    cout<<"Podaj tekst do zakodowania przesuni�cie samog�osek o jedno w prawo"<<endl;

    cin.getline(b, 256);

    kodowanie_jeden(b);

    cout<<"Zaszyfrowany: " <<b<<endl;




    return 0;
}
