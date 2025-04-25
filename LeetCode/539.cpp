#include <bits/stdc++.h>


class Solution {
public:
	int findMinDifference(std::vector<std::string>& timePoints) {
		int res = INT32_MAX;
		std::vector<int> time;
		for (auto t: timePoints)
		{
			int tmp = 0;
			tmp += std::stoi(t.substr(0, 2)) * 60;
			tmp += std::stoi(t.substr(3, 2));
			if(tmp == 0) {
				tmp = 1440;
			}
			time.push_back(tmp);
		}
		int diff;
		std::stable_sort(time.begin(), time.end());
		for (int i = 1; i < time.size(); i++)
		{
			diff = time[i] - time[i - 1];
			res = std::min({res, diff, 1440 - diff});
		}
		diff = time.back() - time[0];
		res = std::min({res, diff, 1440 - diff});
		return res;
	}
};

int main() {
	Solution ans;
	std::vector<std::string> ss{"23:59", "00:00"};
	ans.findMinDifference(ss);
}