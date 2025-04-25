#include <bits/stdc++.h>


double res(double k) {
    return k * k + sqrt(k);
}
const double ep = 0.0000000001;
int main() {
    double k;
    std::cin >> k;
    double l = 0;
    double r = k;
    while(r - l > ep ) {
        double mid = (r + l) / 2;
        double tmp = res(mid);
        if(tmp > k)
            r = mid;
        else {
            l = mid;
        }
    }
    std::cout << std::fixed << std::setprecision(6) << l;
}