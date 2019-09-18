#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    //OTWIERANIE I ODCZYT DANYCH Z PLIKU TXT
    vector<int> dane;
    ifstream plik("dane.txt");


    while(!plik.eof())
    {
        int a;
        plik>>a;
        dane.push_back(a);
    }

    cout<<"odczyt: "<<endl;
    for (int i : dane)
        cout<<i<<endl;


    plik.close();
    //ZAMKNIÊCIE OTWARTEGO PLIKU


    ofstream wyjscie("wyniki.txt");


    for(int i : dane)
        wyjscie<<i<<endl;


    wyjscie.close();

    return 0;
}
