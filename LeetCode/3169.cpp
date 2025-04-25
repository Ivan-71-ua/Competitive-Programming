#include <bits/stdc++.h>




class Solution {
public:
	int countDays(int days, std::vector<std::vector<int>>& meetings) {
		std::stable_sort(meetings.begin(), meetings.end());
		std::deque<int> dqp;
		dqp.push_front(0);
		for (int i = 0; i < meetings.size(); i++) {
			int a = meetings[i][0], b = meetings[i][1];
			int v = dqp.back();
			if(v < a) {
				if(dqp.size() > 1) {
					int f = dqp.back();
					dqp.pop_back();
					int s = dqp.back();
					dqp.pop_back();
					days -= (f - s + 1);
				}
				
				dqp.push_back(a);
				dqp.push_back(b);
			} else {
				int v = dqp.back();
				dqp.pop_back();
				dqp.push_back(std::max(v, b));
			}
		}
		int b = dqp.back();
		dqp.pop_back();
		int a = dqp.back();
		dqp.pop_back();
		days -= (b - a + 1);
		return days;
	}
};

int main() {
	std::vector<std::vector<int>> meetings{{5,7},{1,3},{9,10}};
	Solution s;
	std::cout << s.countDays(57, meetings) << '\n';
}