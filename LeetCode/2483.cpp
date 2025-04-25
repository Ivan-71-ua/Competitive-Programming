#include <bits/stdc++.h>


class Solution {
public:
   int bestClosingTime(std::string customers) {
		int y = std::count(customers.begin(), customers.end(), 'Y');
		//int n = std::count(customers.begin(), customers.end(), 'N');
		//int used_n = 0;
		int min_v = y;
		int min_tp = min_v;
		int id = 0;
		for (int i = 1; i <= customers.size(); i++)
		{
			if(customers[i -1] == 'N') {
				min_tp++;
			} else {
				min_tp--;
			}
			if(min_tp < min_v) {
				min_v = min_tp;
				id = i;
			}
		}
		return id;
	}
};