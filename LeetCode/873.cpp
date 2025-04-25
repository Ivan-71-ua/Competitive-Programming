#include <bits/stdc++.h>



class Solution {
public:
	int lenLongestFibSubseq(std::vector<int>& arr) {
		int n = arr.size();
		int res = 0;
		std::unordered_map<int, int> num_idx;
		for (int i = 0; i < n; i++) {
			num_idx[arr[i]] = i;
		}
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				int f = i, s = j, size = 2;
				while(true) {
					if(!num_idx.count(arr[s] + arr[f]) || num_idx[arr[f] + arr[s]] < s) break;
					int tmp_s = s;
					s = num_idx[arr[s] + arr[f]];
					f = tmp_s;
					size++;
				}
				if(size > 2) {
					res = std::max(res, size);
				}
			}
		}
		return res;
	}
};


int main( ){
	Solution ans;
	std::vector<int> ss{1, 2, 3, 4, 5, 6, 7, 8};
	std::cout << ans.lenLongestFibSubseq(ss);
}