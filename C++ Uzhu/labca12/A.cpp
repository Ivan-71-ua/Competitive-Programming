#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

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

int main() {
    fast;
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++)
    {
        int a, b, x, y;
        std::cin >> a >> b;
        int tp = gsdext(a, b, x, y);
        if(tp == 1) {
            if(x < 0) {
                x += b;
                y -= a;
            }
            std::cout << x << " " << y << '\n';
        } else {
            std::cout << "No Solution\n";
        }
    }

}