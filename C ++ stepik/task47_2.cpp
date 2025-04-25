#include <iostream>
using namespace std;

int main(void) {
    int p, x, y, k, total=0;
    cin >> p >> x >> y >> k;
    total = x * 100 + y; 
    while (k--) {
        total += total * p / 100;
    }
    cout << total / 100 << " " << total % 100;
  return 0;
}