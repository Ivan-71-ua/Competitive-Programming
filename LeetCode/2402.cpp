
#include <bits/stdc++.h>


class Solution {
public:
	int mostBooked(int n, std::vector<std::vector<int>>& meetings) {
		std::vector<int> cnt(n, 0);
		std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<>> used;
		std::priority_queue<int, std::vector<int>, std::greater<>> free;
		for (int i = 0; i < n; i++) {
			free.push(i);
		}
		std::sort(meetings.begin(), meetings.end());
		for (auto q: meetings) {
			int l = q[0], r = q[1];
			while(!used.empty() && used.top().first <= l) {
				int used_door = used.top().second;
				used.pop();
				free.push(used_door);
			}
			if(!free.empty()) {
				int door = free.top();
				free.pop();
				cnt[door]++;
				used.push({r, door});
			} else {
				auto [time, door] = used.top();
				used.pop();
				cnt[door]++;
				used.push({time + r - l, door});
			}
		}
		int id = 0, count = 0;
		for (int i = 0; i < n; i++) {
			if(count < cnt[i]) {
				id = i;
				count = cnt[i];
			}
		}
		return id;
	}
}; 