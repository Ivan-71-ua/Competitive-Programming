#include <bits/stdc++.h>
using namespace std;


int main() {
    int x , a, k; cin >> a >> k;
    x = a;
    x = x>>k;
    x = x<<k;
    cout << (a^x);
}