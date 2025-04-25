#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define int long long

int32_t main() {
	int n;
	std::cin >> n;
	std::vector<std::pair<int, std::pair<int, int>>> res(n +3, {-1, {0, -1}});
	int k = 0;
	int cur_pl = 0;
	int tp;
	std::cin >> tp;
	res[k].first = tp;
	res[k].second.first++;
	res[k].second.second = k;
	cur_pl++;
	for (int i = 1; i < n; i++)
	{
		std::cin >> tp;
		if(res[k].first == tp) {
			res[k].second.first++;
		}
		else {
			k++;
			res[k].first = tp;
			res[k].second.first++;
			res[k].second.second = cur_pl;
		}
		cur_pl++;
	}
	int max_l = res[0].second.second;
	int start = res[0].second.first;
	for (int i = 1; i < n; i++)
	{
		if(res[i].first == -1) {
			break;
		} else{
			if(max_l < res[i].second.first + res[i -1].second.first) {
				max_l = res[i].second.first + res[i - 1].second.first;
				start = res[i - 1].second.second;
			}
		}
	}
	std::cout << start + 1 << ' ' << max_l;
}