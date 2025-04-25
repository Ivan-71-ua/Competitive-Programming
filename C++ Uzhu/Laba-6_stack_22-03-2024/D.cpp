#include <bits/stdc++.h>
#define MAX 10001
#define size 1002
#define int long long

int32_t main() {
	std::vector<int> s;
	int i, j = 1, k = 1, h = 1, n, sayc = 1, sayd = 0;
	std::vector<int> a(MAX), b(MAX), c(MAX), d(MAX);
	std::cin >> n;
	for(i = 1; i <= n; i++)
		std::cin >> a[i];
	s.push_back(a[1]);
	for(i = 2; i <= n; i++) {
		if(a[i] < s.back()) {
				s.push_back(a[i]);
				sayc++;
		}
		else {
				c[k++] = sayc;
				sayc = 1;
				while(a[i] > s.back()) {
					b[j++] = s.back();
					s.pop_back();
					sayd++;
					if(s.empty())
						break;
				}
				d[h++] = sayd;
				s.push_back(a[i]);
				sayd = 0;
		}
	}
	c[k++] = sayc;
	while(!s.empty()) {
		b[j++] = s.back();
		s.pop_back();
		sayd++;
	}
	d[h++] = sayd;
	k--; h--; j--;
	for(i=1; i<j; i++) {
		if(b[i]+1 == b[i+1])
				continue;
		else
				break;
	}
	if(i == j) {
		for(i = 1; i <= k; i++)
			std::cout << "1 " << c[i] << std::endl << "2 " << d[i] << std::endl;
	}
	else
		std::cout << "0" << std::endl;
}
