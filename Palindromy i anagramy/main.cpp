#include <iostream>
#include <vector>

using namespace std;



void palindrom(string wyraz)
{
    string pom = "";

    for (int i = wyraz.length()-1; i >= 0 ; i--)
        pom += wyraz[i];

    cout<<pom<<endl;
}

bool czyAnagram(string wyraz, string anag)
{
    bool fail = false;

    if(wyraz.length() == anag.length())
    {
        for (int i = 0; i< wyraz.length(); i++)
        {
            bool cont = false;
            for(int j = 0; j<wyraz.length(); j++)
            {
                if(wyraz[i] == anag[j]) cont = true ;
            }
            if(cont == false) fail = true;
        }

        if(fail == true) return false;
        else return true;
    }
    else return false;

}





int main()
{
    string a, b, c;
    cout<<"String: "<<endl;
    cin>>a;
    palindrom(a);

    cout<<"Czy anagram string wyjœcia: "<<endl;
    cin>>b;
    cout<<"2 string: "<<endl;
    cin>>c;

    cout<<czyAnagram(b,c);



    return 0;
}
