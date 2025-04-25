#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <array>
#include <numeric>
#include <queue>
#include <deque>
#include <cmath>
#include <climits>
#include <string>

const int ZERO = []()
	{
		std::ios_base::sync_with_stdio(false);
		std::cin.tie(nullptr);
		return 0;
	}();

class AllOne {
	std::map<std::string, int> count;
	std::set<std::pair<int, std::string>> max_min;
public:
	AllOne() {
		
	}
	void inc(string key) {
		int n = count[key];
		count[key]++;
		max_min.insert({ n + 1, key });
		if (n != 0) {
			max_min.erase({ n, key });
		}
	}

	void dec(string key) {
		int n = count[key];
		if (n != 1) {
			count[key]--;
			max_min.insert({ n - 1, key });
			if (n != 0) {
					max_min.erase({ n, key });
			}
		} else {
			max_min.erase({ n, key });
			count.erase(key);
		}
		
	}

	string getMaxKey() {
		if (max_min.empty()) return "";
		return max_min.rbegin()->second;
	}

	string getMinKey() {
		if (max_min.empty()) return "";
		return max_min.begin()->second;
	}
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */