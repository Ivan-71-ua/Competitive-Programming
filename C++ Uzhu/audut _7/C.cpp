#include <bits/stdc++.h>
using namespace std;

int main() {
    int g;
    cin >> g;
    while(g--) {
        long long x, res = 0;
        cin >> x;
        for(int i = 0; x != 0; x = x >> 1, i++) 
        {
            if(!(x & 1)) res += (1LL << i);
        }
        cout << res << endl;
    }
}