#include <bits/stdc++.h>

using namespace std;

void merge_two(vector<int> &A, vector<int> &B, int l, int q, int r)
{
    int i = l, j = q + 1; //  int i to pierwsza na lewo j to pierwsza liczba prawej

    for(int k = l; k <= r; k++)     // pêtla d³ugoœci od l do r w³¹cznie
    {
        if( j > r || (i<=q && A[i] < A[j]))     // JE¯ELI element j jest poza zakresem || (je¿eli lewy element jest w zakresie i lewy jest mniejszy od prawego
        {
            B[k] = A[i];    //TAB pom = A[lewy element]
            i++;
        }
        else
        {
            B[k] = A[j];
            j++;
        }
    }
    //NADPISANIE TABLICY ORYGINALNEJ
    for(int k = l; k <= r; k++)
    {
        A[k] = B[k];
    }
}

void mergeSort(vector<int> &A, vector<int> &B, int l, int r)
{
    if(l<r){
    int q = (l+r)/2;
    mergeSort(A,B,l,q);
    mergeSort(A,B,q+1, r);
    merge_two(A,B,l,q,r);


    }
}

int main()
{
    vector<int> A = {234, 454, 3, 2, 646, 65, 55, 4, 7, 8, 8,3, 2,12,124,2412};
    vector<int> B(A.size(), 0);

    cout<<"BEFORE: "<<endl;
    for(int i : A)
        cout<<i<<" ";


    mergeSort(A,B,0,A.size()-1);


    cout<<"\nAFTER: "<<endl;
    for(int i : A)
        cout<<i<<" ";

    return 0;
}
