

#include <bits/stdc++.h>


class Solution {
public:
	int numberOfArrays(std::vector<int>& differences, int lower, int upper) {
		int minimum = 0, maximum = 0, sum = 0;
		for(auto i: differences) {
			sum += i;
			minimum = std::min(minimum, sum);
			maximum = std::max(maximum, sum);
			if(maximum - minimum > upper - lower) {
				return 0;
			}
		}
		return (upper - lower) - (maximum - minimum) + 1;
	}
};

