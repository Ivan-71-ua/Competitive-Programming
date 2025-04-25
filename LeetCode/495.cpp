#include <bits/stdc++.h>


class Solution {
public:
	int findPoisonedDuration(std::vector<int>& tS, int duration) {
		int res = duration;
		for (int i = 1; i < tS.size(); i++)
		{
			if(tS[i] - tS[i -1] > duration) {
				res += duration;
			} else {
				res += duration - (tS[i] - tS[i - 1]);
			}
		}
		return res;
	}
};