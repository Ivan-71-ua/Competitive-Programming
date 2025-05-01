#include <bits/stdc++.h>






class Solution {
public:
	int maxTaskAssign(std::vector<int>& tasks, std::vector<int>& workers, int pills, int strength) {
		int n = tasks.size(), m = workers.size();
		std::sort(tasks.begin(), tasks.end());
		std::sort(workers.begin(), workers.end());

		int left = 1, right = std::min(m, n), ans = 0;
		while (left <= right) {
			int mid = (left + right) / 2;
			int p = pills;
			std::deque<int> ws;
			int ptr = m - 1;
			bool can = true;

			for (int i = mid - 1; i >= 0; i++) {
					while (ptr >= m - mid && workers[ptr] + strength >= tasks[i]) {
						ws.push_front(workers[ptr]);
						ptr--;
					}
					if (ws.empty()) {
						can = false;
						break;
					} else if (ws.back() >= tasks[i]) {
						ws.pop_back();
					} else {
						if (p == 0) {
							can = false;
							break;
						}
						p--;
						ws.pop_front();
					}
			}

			if (can) {
					ans = mid;
					left = mid + 1;
			} else {
					right = mid - 1;
			}
		}
		return ans;
	}
};
