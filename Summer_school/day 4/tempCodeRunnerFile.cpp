#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
	int start, end;
};

bool compare(const Interval &a, const Interval &b) {
	if (a.end == b.end) {
		return a.start > b.start;
	}
	return a.end < b.end;
}

int main() {
	int n;
	cin >> n;
	vector<Interval> intervals(n);
	
	for (int i = 0; i < n; ++i) {
		cin >> intervals[i].start >> intervals[i].end;
	}
	
	sort(intervals.begin(), intervals.end(), compare);
	
	int count = 0;
	int last_end = -1;
	
	for (const auto &interval : intervals) {
		if (interval.start > last_end) {
			++count;
			last_end = interval.end;
		}
	}
	
	cout << count << endl;
	
	return 0;
}
