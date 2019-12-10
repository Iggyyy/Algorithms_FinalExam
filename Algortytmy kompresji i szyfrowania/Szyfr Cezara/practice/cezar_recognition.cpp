#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream dane("dane_recognition.txt");

    while(!dane.eof())
    {
        string orginal, check;
        dane>>orginal>>check;

        int key;
         if(check[0] >= orginal[0])
            key = check[0] - orginal[0];
        else
            key = 'Z' - orginal[0] + check[0] - 'A' +1;
        bool dobry = true;

        for(int i =0 ;i<orginal.length();i++)
        {
            if(check[i] >= orginal[i])
            {
                  if(check[i] - orginal[i] != key)
                        dobry = false;
            }
            else
            {
                if( 'Z' - orginal[i] + check[i] - 'A' +1 != key)
                        dobry = false;
            }

        }

        cout<<orginal<<" "<<check<<" k: "<<key<<" "<<(dobry == false? "ZLE":"DOBRZE")<<endl;

    }

    return 0;
}
