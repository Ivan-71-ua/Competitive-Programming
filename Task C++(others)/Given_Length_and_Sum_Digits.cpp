#include <bits/stdc++.h>

int main() {
	int m, s;
	std::cin >> m >> s;
	if(s == 0) {
		if(m == 1) {
			std::cout << "0 0";
			return 0;
		} else {
			std::cout << "-1 -1";
			return 0;
		}
	}
	std::string max = "";
	std::string min = "";
	for (int i = 0; i < m; i++)
	{
		int k = std::min(9, s);
		max.push_back('0' + k);
		s -= k;	
	}
	if(s > 0) {
		std::cout << "-1 -1";
		return 0;
	}
	for (int i = m -1; i >= 0; i--)
	{
		min.push_back(max[i]);
	}
	int j = 0;
	while(min[j] == '0') {
		j++;
	}
	min[0]++;
	min[j]--;
	std::cout << min << ' ' << max;
}