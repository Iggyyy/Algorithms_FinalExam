#include <iostream>
#include <vector>
#include <string>
using namespace std;

void parseByChar(string str, char ch, vector<string> &vect)
{

    while(!str.empty())
    {
        if(str.find(ch) != string::npos)
        {
            int dig = str.find(ch);
            vect.push_back(str.substr(0, dig));
            str.erase(0, dig+1);

            cout << dig <<endl;
        }
        else
        {
            cout << str <<endl;
            vect.push_back(str);
            str.erase(0, str.length());
        }
    }

}



int main()
{
    vector<string> parsed;
    string s;
    char a;
    cout<<"string, char"<<endl;
    cin>>s>>a;
    parseByChar(s,a,parsed);


    for(auto i : parsed)
        cout<<i<<endl;

    return 0;
}
