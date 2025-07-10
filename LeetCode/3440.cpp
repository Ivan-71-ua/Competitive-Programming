#include <bits/stdc++.h>




class Solution {
public:
	int maxFreeTime(int eventTime, std::vector<int>& startTime, std::vector<int>& endTime) {
		int n = startTime.size(), res = 0, prev = 0, cur = 0;
		std::vector<int> free;
		free.reserve(n);
		if(startTime[0] > 0) {
			free.push_back(startTime[0]);
			cur = startTime[0];
		}
		for (int i = 1; i < n; i++) {
			free.push_back(startTime[i] - endTime[i - 1]);
		}
		if(eventTime - endTime.back() > 0)
			free.push_back(eventTime - endTime.back());
		std::stable_sort(free.begin(), free.end());
		for (int i = 1; i <= n; i++) {
			prev = cur;
			if(i < n)
				cur = startTime[i] - endTime[i - 1];
			else
				cur = eventTime - endTime.back();
			int diff = endTime[i - 1] - startTime[i - 1];
			int cnt = std::lower_bound(free.begin(), free.end(), diff) - free.begin();
			int cnt = free.size() - cnt;
			if(prev >= diff)
				cnt--;
			if(cur >= diff)
				cnt--;
			if(cnt > 0) {
				res = std::max(res, prev + cur + diff);
			} else {
				res = std::max(res, prev + cur);
			}
		}
		return res;
	}
};

int main() {
	Solution ans;
	std::vector<int> a{0, 17}, b{14, 19};
	ans.maxFreeTime(34, a, b);
}