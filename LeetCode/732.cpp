#include <bits/stdc++.h>


class MyCalendarThree {
public:
	std::map<int, int> time;
	MyCalendarThree() {
		time.clear();
	}
	
	int book(int startTime, int endTime) {
		time[startTime]++;
		time[endTime]--;
		int ans = 0;
		int cur = 0;
		for (auto now: time)
		{
			cur += now.second;
			ans = std::max(ans, cur);
		}
		return ans;
	}
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */