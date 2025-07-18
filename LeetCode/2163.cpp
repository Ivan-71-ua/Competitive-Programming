#include <bits/stdc++.h>



class Solution {
public:
	long long minimumDifference(std::vector<int>& nums) {
        std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);      
      std::cout.tie(nullptr);
		int n = nums.size();
		int k = n / 3;
		std::vector<long long> pref(n), suff(n);
		long long cur_s = 0;
		std::priority_queue<int> q;
		for (int i = 0; i < n; i++) {
			cur_s += nums[i];
			q.push(nums[i]);
			while(q.size() > k) {
				cur_s -= q.top();
				q.pop();
			}
			pref[i] = cur_s;
		}
		while(!q.empty()) {
			q.pop();
		}
		cur_s = 0;
		for (int i = n - 1; i > -1; i--) {
			cur_s += nums[i];
			q.push(-nums[i]);
			while(q.size() > k) {
				cur_s -= abs(q.top());
				q.pop();
			}
			suff[i] = cur_s;
		}
		long  long res = INT64_MAX;
		for (int i = k - 1; i < n - k; i++) {
			res = std::min(res, pref[i] - suff[i + 1]);
		}
		return res;
	}
};


int main() {
	std::vector<int> a{7, 9, 5, 8, 1, 3};

}