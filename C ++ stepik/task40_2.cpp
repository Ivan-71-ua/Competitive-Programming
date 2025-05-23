#include <iostream>

using namespace std;

int main() {
    int n = 1;
    int n_max = 0;
    int cur = -1;
    int prev = -1;

    while (cin >> cur && cur != 0) {
        if (prev != -1) {
            if (cur == prev) {
                ++n;
            }
            else {
                if (n_max < n) {
                    n_max = n;
                }
                n = 1;
            }
        }

        prev = cur;
    }

    if (n > n_max) {
        n_max = n;
    }

    cout << n_max;

    return 0;
}