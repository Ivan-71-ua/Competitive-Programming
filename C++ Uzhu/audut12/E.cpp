#include <bits/stdc++.h>

void HROZNY() {
	std::string s, t = "";
	while (std::cin >> s)
	{
		int n = s.size();
		int k = (n + 1) / 2;
		std::string a = s.substr(0, k);
		std::string b = s.substr(k, n - k);
		std::reverse(begin(b), end(b));
		b = a[0] + b;
		if(a == b && n > 2)
			t = t + " " + a;
	}
	if(t.size() != 0) {
		t.erase(0, 1);
		std::cout << t;
	} else {
		std::cout << -1;
	}
	
}



int main() {
	HROZNY();
}
