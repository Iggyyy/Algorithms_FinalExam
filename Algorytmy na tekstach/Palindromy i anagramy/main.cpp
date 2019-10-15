#include <iostream>
#include <vector>
#include <string>

using namespace std;



void palindrom(string wyraz)
{
    string pom = "";

    for (int i = wyraz.length()-1; i >= 0 ; i--)
        pom += wyraz[i];

    cout<<pom<<endl;
}

bool czyPalind(string wyraz, string palind)
{
    if(wyraz.length() != palind.length()) return false;



    for(int i =0; i<wyraz.length(); i++)
    {
      int j = wyraz.length()-1-i;
      if(wyraz[j] != palind[i]) return false;
    }

    return true;


}

bool czyAnagram(string wyraz, string anag)
{
    vector<int> licz(126, 0);

    if(wyraz.length() != anag.length()) return false;

    for(int i : wyraz)
        licz[i]++;
    for(int i : anag)
        licz[i]--;
    for(int i : licz)
        if(i != 0) return false;
    return true;



}





int main()
{
    string a, b, c, d, e;
    cout<<"String: "<<endl;
    cin>>a;
    palindrom(a);

    cout<<"Czy anagram string wyjœcia: "<<endl;
    cin>>b;
    cout<<"2 string: "<<endl;
    cin>>c;

    cout<<czyAnagram(b,c)<<'\n';

    cout<<"Czy anagram string wyjœcia: "<<endl;
    cin>>d;
    cout<<"2 string: "<<endl;
    cin>>e;
    cout<<czyPalind(d,e);

    return 0;
}
