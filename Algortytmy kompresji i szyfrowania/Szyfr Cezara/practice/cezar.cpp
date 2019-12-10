#include <bits/stdc++.h>

using namespace std;


int main()
{
    fstream dane("dane.txt");

    while(!dane.eof())
    {
        string input,wyr;
        int key;

        dane>>input>>key;

        key %= 'Z'-'A' +1;
        wyr = input;

        //ENCODING
        for(int i =0; i<wyr.length(); i++)
        {
            if(wyr[i] + key <= 'Z')
                wyr[i]+=key;
            else
                wyr[i] = 'A' + (key- 'Z' + wyr[i]) -1;

        }





        cout<<input<<" k:"<<key<<" encoded: "<<wyr;


        //DECODING

        for(int i =0; i<wyr.length(); i++)
        {
            if(wyr[i]-key >= 'A')
                wyr[i]-=key;
            else
                wyr[i] = 'Z' - (key - wyr[i] +'A' -1);
        }
        cout<<" decoded: "<<wyr<<endl;

    }


    dane.close();

    return 0;
}
