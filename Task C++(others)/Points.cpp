// LUOGU_RID: 126420474
/*
 * @Author:             cmk666
 * @Created time:       2023-09-28 09:34:09
 * @Last Modified time: 2023-09-28 10:29:58
 */
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")

#include<map>
#include<iostream>
#include<set>
#include<vector>
#include<algorithm>




std::set<int> O_X;
std::map<int, std::set<int>> O_Y;

int main() {
	std::ios::sync_with_stdio(false);
   std::cin.tie(nullptr);
   std::cout.tie(nullptr);
	int t;
	std::cin >> t;
	while(t--) {
		std::string what;
		int x, y;
		std::cin >> what >> x >> y;
		if(what == "add") {
			O_X.insert(x);
			O_Y[x].insert(y);
		} else if(what == "find") {
			int a_x, a_y;
			a_x = a_y = -1;
			auto low = O_X.upper_bound(x);
			while(low != O_X.end()) {
				int tmp_x = *low;
				auto tmp_y = O_Y[tmp_x].upper_bound(y);
				if(tmp_y != O_Y[tmp_x].end()) {
					a_x = tmp_x;
					a_y = *tmp_y;
					break;
				}
				low++;
			}
			if(a_x == -1) {
				std::cout << -1 << '\n';
			} else {
				std::cout << a_x << ' ' << a_y << '\n';
			}
		} else if(what == "remove") {
			O_Y[x].erase(y);
			if(O_Y[x].empty()) {
				O_X.erase(x);
			}
		}
	}
}