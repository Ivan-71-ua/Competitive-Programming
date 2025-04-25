#include <bits/stdc++.h>
#include <bitset>

using namespace std;

int main() {
	int a, b;
	string s, s1;
	cin >> a >> b;
	cin >> s >> s1;
	int decimalNumber1 = 0,decimalNumber2 = 0;
   int power = 0;
	for (int i = a - 1; i >= 0; i--) {
      if (s[i] == '1') {
            decimalNumber1 += pow(2, power);
      }
      power++;
   }
	power = 0;
	for (int i = b - 1; i >= 0; i--) {
      if (s1[i] == '1') {
            decimalNumber2 += pow(2, power);
      }
      power++;
   }
	int result = decimalNumber1 ^ decimalNumber2;
	int k = 0, p = 1;
	while(result >= (p << 1)) {
		p = p << 1;
		k++;
	}
   for (int i = k - 1; i >= 0; --i) {
      int bit = result & 1;
		result = result >> 1;
		cout << bit;
	}
}