#include <bits/stdc++.h>
using namespace std;



void simple ( long long a){
    if((a & (a - 1)) == 0) {
        int k = 0;
        while (a != 1) {
            a = a >> 1;
            k++;
        }
        cout << 2 << "^" << k;
    }
    else {
        int p = 0;
        for (int i = 2; ;)
        {


            if(a % i == 0) {
                a /= i;
                p++;
            }
            else if(p >= 1){
                if(p == 1) {
                    if(a == 1) {
                        cout << i;
                        break;
                    }
                    else {
                        cout << i << "*";
                    }

                }
                if(p > 1) {
                    cout << i << "^" << p << "*";
                }
                i++;
                p = 0;
            }
            else if(p == 0){
                i++;
            }

        }
    }


}

int main() {
    long long n;
    cin >> n;
    simple(n);
}