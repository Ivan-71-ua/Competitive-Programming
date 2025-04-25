#include <bits/stdc++.h>


class MyCalendar {
	std::set<std::pair<int, int>> s_to_e;
public:
	MyCalendar() {
	}
	bool book(int start, int end) {
		auto num = s_to_e.lower_bound({start, end});
		if(num != s_to_e.end() && num->first < end)
			return false;
		if(num != s_to_e.begin()) {
			num--;
			if(num->second > start) return false;
		}	
		s_to_e.insert({start, end});
		return true;
	}
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

int main() {
	MyCalendar *obj = new MyCalendar();
	obj->book(33, 51);
	obj->book(35, 48);
}