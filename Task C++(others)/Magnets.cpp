#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, k = 1;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n - 1; i++) {
        if(arr[i] != arr[i + 1]) {
            k++;
        }
    }
    cout << k;
}
