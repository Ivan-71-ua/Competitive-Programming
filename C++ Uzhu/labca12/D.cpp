#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define int long long

int gsdext(int a,int b, int &x, int &y) {
    if(b == 0) {
        y = 0;
        x = 1;
        return a;
    }
    int d = gsdext(b, a % b, x, y);
    x = x - (a / b) * y;
    std::swap(x, y);
    return d;
}

int_fast32_t main() {
    fast;
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++)
    {
        int x, k, p, q, a, b;
        std::cin >> x >> k;
        if(x % k == 0) {
            std::cout << 0 << " " << k << '\n';
        } else {
            b = floor((double)x / k);
            a = ceil((double)x / k);
            int d = gsdext(b, a, p, q);
            std::cout << x  * p << " " << x  * q << '\n';
        }
    }
}


//https://site.ada.edu.az/~medv/acm/Docs%20e-olimp/Volume%2016/1565.htm