#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double p, x, y;
    int k;
    cin >> p >> x >> y >> k;
    
    double sum = (x * 100 + y);
    
    while (k--) sum = trunc(sum + sum * (p / 100));
    
    cout << trunc(sum / 100) << " " << sum - trunc(sum/100)*100;
}