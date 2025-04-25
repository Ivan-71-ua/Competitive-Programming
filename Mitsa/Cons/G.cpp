#include <bits/stdc++.h>
#define int long long

double W, H, L;


bool can(double k) {
    double osn = W / (k + 1.0);
    double reb = L / (2.0 * (k + 1.0));
    
    if(H > sqrtl((reb * reb) - (osn * osn) / 4.0)) {
        return true;
    }
    return false;
}

int32_t main() {
    
    std::cin >> W >> H >> L;
    int l = 0, r = 10000000000000000;
    while(r - l > 1) {
        int mid = (r + l) / 2.0;
        if(can(mid)) { 
            r = mid;
        } else {
            l = mid;
        }
    }
    if (can(l)) {
        std::cout << l;
    } else {
        std::cout << l + 1;
    }
}