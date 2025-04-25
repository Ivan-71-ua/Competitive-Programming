#include <bits/stdc++.h>
using namespace std;
int Strlens_my(const char *string) {
	int k = 0;
	for (int i = 0;;i++) {
		if(string[i] != '\0') {
			k++;
		}
		else {
			break;
		}
	}
	return k;
}

int main() {
	char *str;
	cin >> str;
	cout << Strlens_my(str);
}