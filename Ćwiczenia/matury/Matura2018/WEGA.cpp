#include <bits/stdc++.h>

using namespace std;



void zad1()
{
     fstream dane("sygnaly.txt");
     ofstream wyniki("wyniki4.txt",ios::out);

     string slowo ="";
     int it =1;
     while(!dane.eof())
     {
         string line;
         dane>>line;

        if(it%40==0)
            {
                //cout<<it<<" "<<line[9]<<endl;
                slowo += line[9];
            }
        it++;

     }
     dane.close();
     cout<<"zad1: "<<slowo<<endl;
     wyniki<<"4.1\n"<<slowo<<endl;
}
void zad2()
{
    ifstream dane("sygnaly.txt", ios::in);
    ofstream wyniki("wyniki4.txt", ios::app);
    string slowo= "start";
    int liter = 0;

    while(!dane.eof())
    {
        string line;
        dane>>line;

        //cout<<line<<endl;
        vector<int> literki(26,0);
        for(int i = 0; i< line.length(); i++)
        {
            literki[(int)line[i]%26]+=1;
        }
        int sum =0;
        for(int i =0; i<literki.size(); i++)
        {
            if(literki[i] > 0)
                sum++;
            //cout<<literki[i];
        }
        if(sum > liter)
        {
            liter = sum;
            slowo = line;
        }
        //cout<<endl;

    }
    cout<<"4.2\n"<<slowo<<" "<<liter<<endl;
    wyniki<<"4.2\n"<<slowo<<" "<<liter<<endl;
    dane.close();
}
void zad3()
{
    fstream dane("sygnaly.txt");
    ofstream wyniki("wyniki4.txt",ios::app);
cout<<"4.3"<<endl;
 wyniki<<"4.3\n"<<endl;
     while(!dane.eof())
     {
         string line;
         dane>>line;

        sort(line.begin(), line.end());
        int roznica = line[line.length()-1] - line[0];

        if(roznica<=10)
        {
           cout<<line<<" "<<roznica<<endl;
            wyniki<<line<<endl;
        }

     }


     dane.close();
     //cout<<"zad1: "<<slowo<<endl;

}


int main()
{
    zad1();
    zad2();
    zad3();

    return 0;
}
