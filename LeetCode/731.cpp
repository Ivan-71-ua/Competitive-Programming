#include <bits/stdc++.h>


class MyCalendarTwo {
	std::vector<std::pair<int, int>> non_over;
	std::vector<std::pair<int, int>> over;
public:
	MyCalendarTwo() {
		
	}
	bool book(int start, int end) {
		for (auto pr: over)
		{
			if(!(end <= pr.first || pr.second <= start)) {
				return false;
			}
		}
		for (auto pr:non_over)
		{
			if(!(end <= pr.first || pr.second <= start)) {
				over.push_back({std::max(pr.first, start), std::min(pr.second, end)});
			}
		}
		non_over.push_back({start, end});
		return true;
	}
};