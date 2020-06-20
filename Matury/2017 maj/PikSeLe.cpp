#include <bits/stdc++.h>

using namespace std;

vector< vector<int>> obraz;
ofstream wyniki;




void zad1()
{
    int najw = 0, najm = 300;
    for(int i = 0 ; i< obraz.size(); i++)
    {
        for(int j = 0; j<obraz[i].size(); j++)
        {
            najw = max(obraz[i][j], najw);
            najm = min(obraz[i][j], najm);
        }
    }

    cout<<"ZAD 1\nMaks: "<<najw<<"\nMin: "<<najm<<endl;
    wyniki<<"ZAD 1\nMaks: "<<najw<<"\nMin: "<<najm<<endl;
}
bool czySym(vector<int> wiersz)
{
    int l  = 0,  r = 319;
    bool odp = true;
    while(l<r)
    {
        if(wiersz[l] != wiersz[r])
        {
            //cout<<wiersz[l]<<" "<<wiersz[r]<<endl;
            odp =  false;

        }
        l++;
        r--;
    }
    return odp;


}
void zad2()
{
    int counter = 0;
    for(int i =  0; i< 200; i++)
    {
        if( czySym(obraz[i]) == false)
            counter++;
    }

    cout<<"ZAD 2\nIle wierszy usunac: "<<counter<<endl;
    wyniki<<"ZAD 2\nIle wierszy usunac: "<<counter<<endl;
}


bool czyKontrast(int row, int col)
{
    int val = obraz[row][col];

    if(row < 199)
    {
        if(abs(obraz[row+1][col]-val) >128)
            return true;
    }
    if(row > 0)
    {
        if(abs(obraz[row-1][col]-val) >128)
            return true;
    }
    if(col < 319)
    {
        if(abs(obraz[row][col+1]-val) >128)
            return true;
    }
    if(col > 0)
    {
        if(abs(obraz[row][col-1]-val) >128)
            return true;
    }

    return false;
}

void zad3()
{
    int counter = 0;
    for(int i = 0; i<200; i++)
    {

        for(int j = 0; j<320; j++)
        {
            if( czyKontrast(i,j) == true)
                counter++;
           // if(i == 198) cout<<j<<endl;
        }
    }

    cout<<"ZAD 3\nKontrastujacych: "<<counter<<endl;
    wyniki<<"ZAD 3\nKontrastujacych: "<<counter<<endl;
}



int main()
{
    ifstream dane("dane.txt");
    for(int i = 0; i < 200; i++)
    {
        vector<int> wiersz;
        for( int j = 0; j< 320; j++)
        {
            int x;
            dane>>x;
            wiersz.push_back(x);
        }
        obraz.push_back(wiersz);
    }
    dane.close();
    wyniki.open("wyniki6.txt");

    /*for(int i = 0; i < 200; i++)
    {
        for( int j = 0; j< 320; j++)
        {
            cout<<obraz[i][j]<<" ";
        }
        cout<<endl;
    }
*/


   zad1(); wyniki<<endl;
   zad2(); wyniki<<endl;
   zad3();


    wyniki.close();
    return 0;
}
