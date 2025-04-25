#include <bits/stdc++.h>

class Solution {
	std::unordered_map<int, int> hash;
	int maxSum(int id, std::vector<int>& arr, int k) {
		if(hash[id]) {
			return hash[id];
		}
		int cur_max = 0;
		int res = 0;
		for (int i = id; i < std::min((int)arr.size(), id + k); i++)
		{
			cur_max = std::max(cur_max, arr[i]);
			int window_size = i - id + 1;
			res = std::max(res, maxSum(i + 1, arr, k) + cur_max * window_size);
		}
		hash[id] = res;
		return res;
	}
public:
	int maxSumAfterPartitioning(std::vector<int>& arr, int k) {
		return maxSum(0, arr, k);
	}
};

int main() {
	Solution ans;
	std::vector<int> ss{1, 15, 7, 9, 2, 5, 10};
	ans.maxSumAfterPartitioning(ss, 3);
}