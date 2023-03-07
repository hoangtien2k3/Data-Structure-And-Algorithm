
/*
    Cho một dãy gồm n số nguyên và một số nguyên x. 
    Hãy đếm xem trong dãy có bao nhiêu phần tử có giá trị x.
    
*/

#include<bits/stdc++.h>
using namespace std;

int count(int *arr, int l, int r, int x) {
    if (l == r) {
        if (arr[l] == x || arr[r] == x) {
            return 1;
        } else return 0;
    } else {
        int mid = (l + r) / 2;
        return count(arr, l, mid, x) + count(arr, mid + 1, r, x);
    }
}

int main() {
    int n; cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int x; cin >> x;
    cout << count(arr, 0, n - 1, x);
    delete arr;
    return 0;
}