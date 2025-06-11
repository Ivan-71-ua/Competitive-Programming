#include <bits/stdc++.h>



class Solution {
public:
	int maxDifference(std::string s, int k) {
		int n = s.size();
		int ans = INT_MIN;
		for (char a = '0'; a <= '4'; a++) {
			for (char b = '0'; b <= '4'; b++) {
				if (a == b) continue;
				std::vector<int> best(4, INT_MAX);
				int cnt_a = 0, cnt_b = 0;
				int prev_a = 0, prev_b = 0;
				int left = -1;
				for (int right = 0; right < n; right++) {
					if (s[right] == a) cnt_a++;
					if (s[right] == b) cnt_b++;
					while (right - left >= k && (cnt_b - prev_b >= 2)) {
						int left_status = getStatus(prev_a, prev_b);
						best[left_status] = std::min(best[left_status], prev_a - prev_b);
						left++;
						if (s[left] == a) prev_a++;
						if (s[left] == b) prev_b++;
					}
					int right_status = getStatus(cnt_a, cnt_b);
					int required_status = right_status ^ 0b10;
					if (best[required_status] != INT_MAX) {
						ans = std::max(ans, cnt_a - cnt_b - best[required_status]);
					}
				}
			}
		}
		return ans == INT_MIN ? -1 : ans;
	}
private:
	int getStatus(int cnt_a, int cnt_b) {
		return ((cnt_a & 1) << 1) | (cnt_b & 1);
	}
};
