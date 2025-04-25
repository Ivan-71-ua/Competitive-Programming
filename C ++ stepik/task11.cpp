#include <iostream>

using namespace std;

int main() {
	int v, t, s, s1, s2;
	s = 109;
	cin >> v >> t;
	s1 = (v * t) % 109;
	s2 = (s1 + 109) % 109;

	cout << s2;
} 