#include <bits/stdc++.h>



class Solution {
public:
	int minSetSize(std::vector<int>& arr) {
		int res = 0, n = arr.size(), total = 0;
		std::unordered_map<int, int> freq;
		for (int num : arr) {
			freq[num]++;
		}
		std::vector<int> cnt;
		for( auto [_, c]: freq) {
			cnt.push_back(c);
		}
		std::stable_sort(cnt.begin(), cnt.end(), std::greater<int>());
		for(auto c : cnt) {
			total += c;
			res++;
			if(total >= n / 2) {
				return res;
			}
		}
		return -1;
	}
};