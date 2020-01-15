#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void merge_two(vector<int> &first, vector<int> &second)
{
    vector<int> ret;
    int a = first.size()-1, b= second.size()-1;
    int i=0;
    for(int i : first)
        cout<<i<<" ";
    cout<<endl;
    for(int i : second)
        cout<<i<<" ";
    cout<<"\na: "<<a<<" b: "<<b<<" i: "<<i<<endl;


    while(a>=0 &&b>=0)
    {
        cout<<"\na: "<<a<<" b: "<<b<<" i: "<<i<<endl;
        if(i<first.size()-1 && i < second.size()-1)
        {
            if(first[i] < second[i])
            {
                ret.push_back(first[i]);
                a--;
                cout<<"pushed from first"<<endl;
            }
            else
            {
                ret.push_back(second[i]);
                b--;
                cout<<"pushed from second"<<endl;
            }
        }
        else
        {
            if(i > first.size()-1)
            {
                ret.push_back(second[i]);
                b--;
                cout<<"pushed from second*"<<endl;
            }
            else
            {
                ret.push_back(first[i]);
                a--;
                cout<<"pushed from first*"<<endl;
            }
        }

        i++;
    }
    for(int i : ret)
        cout<<i<<" ";
}


int main()
{

        vector<int> a = {1,2,3,4,5,6,10};
        vector<int> b = {3,5,6,7,11};

        merge_two(a,b);
        cout<<"Merge"<<endl;


    return 0;
}
