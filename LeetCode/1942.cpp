#include <bits/stdc++.h>


class Solution {
public:
	int smallestChair(std::vector<std::vector<int>>& times, int targetFriend) {
		int n = times.size();
		std::vector<int> ordered(n);
		for (int i = 0; i < n; i++)
		{
			ordered[i] = i;
		}
		std::stable_sort(ordered.begin(), ordered.end(), [&times](int a, int b)
							  { return times[a][0] < times[b][0]; });
		std::priority_queue<int, std::vector<int>, std::greater<int>> free_seat;
		for (int i = 0; i < n; i++)
		{
			free_seat.push(i);
		}
		
		std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> taked_seat;
		for (auto &p: ordered)
		{
			int st = times[p][0], fn = times[p][1];
			while(!taked_seat.empty() && taked_seat.top().first <= st) {
				free_seat.push(taked_seat.top().second);
				taked_seat.pop();
			}
			int seat = free_seat.top();
			free_seat.pop();
			if(p == targetFriend)
				return seat;
			taked_seat.push({fn, seat});
		}
		return -1;
	}
}; 