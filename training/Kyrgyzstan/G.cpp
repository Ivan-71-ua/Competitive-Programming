#include <iostream>
#include <cmath>

using namespace std;

void gcdext(int a, int b, int& d, int& x, int& y) {
    if (b == 0) {
        d = a;
        x = 1;
        y = 0;
        return;
    }
    gcdext(b, a % b, d, x, y);
    int temp = y;
    y = x - (a / b) * y;
    x = temp;
}

int main() {
    int a, b, n;
    cin >> a >> b >> n;

    int x, y, d;
    gcdext(a, b, d, x, y);

    
    if (n % d != 0) {
        cout << 0 << endl;
        return 0;
    }

   
    int k = n / d;
    x *= k;
    y *= k;

    int a_d = a / d;
    int b_d = b / d;

  
    long long t1 = (long long) ceil(-1.0 * x / b_d); 
    long long t2 = (long long) floor(1.0 * y / a_d); 


    if (t1 > t2) {
        cout << 0 << endl;
        return 0;
    }

   
    long long x1 = x + t1 * b_d;
    long long y1 = y - t1 * a_d;
    long long res1 = x1 + y1;

    cout << res1 << endl;
    return 0;
}
