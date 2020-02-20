#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

void Merge(vi& A, vi& B, int l, int q, int r) {
    int i = l, j = q + 1;

    for (int k = l; k <= r; k++) {
        if ( j > r || (i <= q && A[i] < A[j]))
            B[k] = A[i++];
        else
            B[k] = A[j++];
    }

    for (int k = l; k <= r; k++) {
        A[k] = B[k];
    }
}

void MergeSort(vi& A, vi& B, int l, int r) {
    if ( l < r ) {
        int q = l + (r - l)/2;
        MergeSort(A, B, l, q);
        MergeSort(A, B, q + 1, r);
        Merge(A, B, l, q, r);
    }
}

int main() {
    vi A { 20, 10, 12391923, 8123, 1283, 1238, 129412, -129124, -12489, 2341, 145, 129, 124 };
    vi B(A.size(), 0);

    MergeSort(A, B, 0, A.size() - 1);

    for (int i : A) cout << i << " ";
    cout << "\n";

    return 0;
}
