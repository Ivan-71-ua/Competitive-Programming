#include <bits/stdc++.h>


class Solution {
public:
	double averageWaitingTime(std::vector<std::vector<int>>& customers) {
		double all_vetings = 0;
		int cur_time = 0;
		for (int i = 0; i < customers.size(); i++) {
			//int finish = customers[i][0] + customers[i][1];
			if(cur_time > customers[i][0]) {
				all_vetings += cur_time + customers[i][1] - customers[i][0];
				cur_time = cur_time + customers[i][1];
			} else {
				all_vetings += customers[i][1];
				cur_time = customers[i][0] + customers[i][1];
			}
		}
		return all_vetings / customers.size();
	}
};