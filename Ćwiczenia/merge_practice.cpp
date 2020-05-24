#include <bits/stdc++.h>

using namespace std;



void Merge(vector<int> &A, vector<int> &B, int l, int s, int r)
{
    int i = l, j = s+1;

    for(int k = l; k<=r; k++)
    {
        if( j > r || (i <=s && A[i] < A[j]))
            B[k] = A[i++];
        else
            B[k] = A[j++];
    }

    for(int k = l; k<= r; k++)
        A[k] = B[k];

}

void merge_practice(vector<int> &A, vector<int> &B, int l, int s, int r)
{
    int i = l, j = s+1;
    for(int k = l; k<=r; k++)
    {
        if(j>r || (i<=s && A[i] < A[j]))
            B[k] = A[i++];
        else
            B[k] = A[j++];
    }


    for(int k = l; k<=r; k++)
        A[k] = B[k];
}

void MergeSort(vector<int> &A, vector<int> &B, int l, int r)
{
    if(l<r)
    {
        int s = (r+l)/2;
        MergeSort(A,B,l, s);
        MergeSort(A,B,s+1, r);
        merge_practice(A,B,l,s,r);
    }

}



int main()
{
    vector<int> TAB = {2,5,1,2,6,3,5,7,8};
    vector<int> B(TAB.size(), 0);

    MergeSort(TAB, B,0, TAB.size()-1);

    for(int i : TAB)
        cout<<i<<" ";


    return 0;
}
