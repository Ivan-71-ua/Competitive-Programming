#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int invers(std::string s)
{
	int res = 0;
	for (int i = 0; i < s.size() - 1; i++) {
		for (int j = i + 1; j < s.size(); j++)
		{
			if(s[i] > s[j])
				res++;
		}
	}
	return res;
}
bool comp(std::pair<int, std::string> a, std::pair<int, std::string> b) {
	return a.first < b.first;
}

int main() {
	int t;
	std::cin >> t;
	while(t--) {
		int s, n;
		std::cin >> s >> n;
		std::vector<std::pair<int, std::string>> res(n);
		for (int i = 0; i < n; i++)
		{
			std::string s;
			std::cin >> s;
			res[i] = std::make_pair(invers(s), s);
		}
		std::stable_sort(res.begin(), res.end(), comp);
		for (int i = 0; i < n; i++)
		{
			std::cout << res[i].second << '\n';
		}
		std::cout << '\n';
	}
}