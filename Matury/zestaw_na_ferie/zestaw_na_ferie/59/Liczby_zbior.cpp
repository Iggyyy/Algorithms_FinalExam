#include <bits/stdc++.h>
using namespace std;
ofstream wyniki;
vector<int> liczby;
static int moc = 1;
static int maks  = 0, minim = 2e9;

bool czyPierwsza(int a)
{
    for(int i =2; i<sqrt(a); i++)
    {
        if(a%i == 0) return false;
    }
    return true;
}

void zad1()
{
    wyniki<<"zad1: "<<endl;
    cout<<"Ile dobrych: ";
    int licznik = 0;
    for(int i =0; i<liczby.size(); i++)
    {
        int dzielnik = 2;
        vector<int> dzielniki;
        int liczba = liczby[i];
        while(liczba>1)
        {
            if(liczba%dzielnik == 0)
            {
                bool zawiera = false;
                for(int j = 0; j<dzielniki.size(); j++)
                {
                    if(dzielniki[j] == dzielnik)
                        zawiera = true;
                }
               if(zawiera == false) dzielniki.push_back(dzielnik);
                liczba/=dzielnik;
            }
            else
                dzielnik++;
        }

        int roznych =0;
        if(dzielniki.size() == 3)
        {
            for(int k = 0; k < 3; k++)
            {
                if(dzielniki[k]%2 != 0 )
                {
                    if(czyPierwsza(dzielniki[k]) == true)
                        roznych++;
                }
            }
        }

        if(roznych == 3)
        {

             licznik++;
               cout<<licznik<<" ";
        }
    }
    wyniki<<licznik;


}

void zad2()
{
    wyniki<<"zad2:\n ";
    int licznik = 0;
    for(int i =0; i<liczby.size(); i++)
    {
        int org = liczby[i];
        string od = "";
        int tmp = org;
        while(tmp != 0)
        {
            int pom = tmp%10;
            tmp/=10;
            od +=to_string(pom);
        }
        int odwr = atoi(od.c_str());
        int sum = odwr + org;


        //bool palindrome = true;
        tmp = sum;
        od="";
        while(tmp != 0)
        {
            int pom = tmp%10;
            tmp/=10;
            od +=to_string(pom);
        }
        odwr = atoi(od.c_str());

        if(odwr == sum)
            {
                licznik++;
            }



    }
    wyniki<<licznik<<endl;

}

vector<int> iloczyn(int a, int moc, int ostat)
{
    int ilo = 1, pom = a;
    while (a > 0)
    {
        ilo *= a%10;
        //cout<<ilo<<" "<<a<<endl;
        a/=10;
    }
    if(ilo < 10)
        {
            return vector<int> {ilo,moc,pom};
        }

    moc+=1;
    //cout<<moc<<endl;
    return iloczyn(ilo, moc, ostat);

}

void zad3()
{
    int  najw = 0, najm = 2e9;
    vector<int> moce(9,0);

    for(int i = 0; i<liczby.size(); i++)
    {


    int liczba = liczby[i];


    vector<int> wy = iloczyn(liczba, moc, 0);
    int moc = wy[1];
    int ostatni = wy[2];

    moce[moc]++;

    if(ostatni > najw)
        najw = ostatni;
    if(ostatni < najm)
        najm = ostatni;

    }
    wyniki<<"zad3:\n";
    wyniki<<"Najmniejszy: "<<najm<<"\nNajwiekszy: "<<najw<<endl;
    for(int i = 1; i<moce.size(); i++)
        wyniki<<i<<": "<<moce[i]<<endl;


}

int main()
{
    wyniki.open("wyniki_liczby.txt");
    ifstream dane("liczby.txt");
    while(!dane.eof())
    {
        int a;
        dane>>a;
        liczby.push_back(a);
    }
    cout<<"wczytano"<<endl;

    zad1();
    wyniki<<endl;
    zad2();
    zad3();

    wyniki.close();
    return 0;
}
