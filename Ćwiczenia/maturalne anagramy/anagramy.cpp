#include <bits/stdc++.h>
using namespace std;
fstream wyniki;
void zad6_1()
{
    //ILE SLOW W PLIKU TXT KONCZY SIE NA LITERE "A"
    ifstream dane("test.txt", ios::in);
    int counter = 0;
    while(!dane.eof())
    {
        string first;
        dane>>first;
        if(first[first.length()-1] == 'A')
            counter++;
    }
    cout<<"Konczacych sie na A: "<<counter<<endl;
    wyniki<<"6.1\n"<<counter<<endl;
    dane.close();

}

void zad6_2()
{
     //Ile par spelnia warunek ¿e lewa zawiera siê w prawej
    ifstream dane("test.txt", ios::in);
    int counter = 0;
    while(!dane.eof())
    {
        string first,second;
        dane>>first>>second;
        //bool zawiera = true;
        if(first.length() <= second.length())
        {
            for(int i =0; i+first.length()-1<second.length(); i++)
            {
                bool pod = true;
                for(int j =0; j<first.length(); j++)
                {
                    if(first[j] != second[i+j])
                        pod = false;
                }
                if(pod == true)
                {
                    counter++;
                    break;
                }
            }
        }

    }
    cout<<"Podciagow: "<<counter<<endl;
    wyniki<<"6.2\n"<<counter<<endl;
    dane.close();
}

void zad6_3()
{
    //ANAGRAMY
    cout<<"ANAGRAMY:"<<endl;
    wyniki<<"6.3"<<endl;
    ifstream dane("test.txt", ios::in);
    while(!dane.eof())
    {
        string a,b;
        dane>>a>>b;
        vector<int> aliterki(26,0);
        vector<int> bliterki(26,0);
        if(a.length() == b.length())
        {
            for(int i =0; i<a.length(); i++)
            {
                aliterki[a[i]%26]++;
                bliterki[b[i]%26]++;
            }

            bool anag = true;
            for(int i =0; i<aliterki.size(); i++)
            {
                if(aliterki[i] != bliterki[i])
                {
                    anag = false;
                    break;
                }
            }
            if(anag == true)
                {
                    cout<<a<<" "<<b<<endl;
                    wyniki<<a<<" "<<b<<endl;
                }
        }
    }

    dane.close();
}

int main()
{
    wyniki.open("wyniki6.txt");
    zad6_1();
    zad6_2();
    zad6_3();
    cout<<"WSZYSTKIE WYNIKI ZAPISANO DO PLIKU 'wyniki6.txt'"<<endl;
}
