#include <bits/stdc++.h>
#define int long long
int cmp(std::pair<int, int> a, std::pair<int, int> b) {
	if(a.first == b.first) {
		return a.second < b.second;
	}
	return a.first < b.first;
}

int prise(std::vector<std::pair<int, int>> &res, int x) {
	int ans = 0;
	for (int i = 0; i < res.size(); i++)
	{
		ans += abs(res[x].first - res[i].first) * res[i].second;
	}
	return ans;
}

int search(std::vector<std::pair<int, int>> &res) {
	int L = 0;
	int R = res.size() - 1;
	while(R - L >= 3) {
		int a = L + (R - L) / 3;
		int b = L + 2 * (R - L) / 3;
		if (prise(res, a) > prise(res, b))
				L = a;
		else
				R = b;
	}
	int an = prise(res, L++);
	while (L <= R)
		an = std::min(an, prise(res, L++));
	return an;
}

int32_t main() {
	int q;
	std::cin >> q;
	std::vector<std::pair<int, int>> res(q);
	for (int i = 0; i < q; i++)
	{
		int k;
		std::cin >> k;
		res[i].first = k;
	}
	for (int i = 0; i < q; i++)
	{
		int k;
		std::cin >> k;
		res[i].second = k;
	}
	std::stable_sort(res.begin(), res.end(), cmp);
	std::cout << search(res);
}