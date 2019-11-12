#include <iostream>
#include <cstring>
using namespace std;



bool czyZawiera(char *tekst, char *wzorzec)
{
    bool wzor = true;
    for(int i =0; i<strlen(tekst) - strlen(wzorzec) + 1; i++)
    {
        wzor = true;

        for(int j =0; j<strlen(wzorzec); j++)
        {
            if(tekst[j+i] != wzorzec[j])
                {
                    wzor = false;
                    break;
                }
        }

        if(wzor == true)
        {
            cout<<"Znaleziono na pozycji: "<<i<<endl;
            return true;
        }

    }

    return false;

}


int main()
{
    cout<<"Podaj teskt: "<<endl;
    char tekst[256];
    cin.getline(tekst, 256);

    cout<<"Wzorzec: "<<endl;
    char wzorzec[256];
    cin.getline(wzorzec, 256);

    cout<<(czyZawiera(tekst,wzorzec) == 1? "Tekst posiada wzorzec": "tekst nie posiada wzorca")<<endl;


   // cout << "Hello world!" << endl;
    return 0;
}
