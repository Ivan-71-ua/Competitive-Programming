#include <bits/stdc++.h>

class Solution {
	bool isBalance(std::vector<int> &charFreq) {
		int MAX = -1;
		int MIN = 1001;
		for (auto &&now : charFreq)
		{
			if(now > 0) {
				MAX = std::max(MAX, now);
				MIN = std::min(MIN, now);
			}
		}
		return MAX == MIN;
	}

public:
	int minimumSubstringsInPartition(std::string s) {
		int N = s.size();
		std::vector<int> DP(N, N + 1);
		for (int end = 0; end < N; end++)
		{
			std::vector<int> charFreq(26, 0);
			for (int start  = end; start >=0 ; start--)
			{
				charFreq[s[start] - 'a']++;
				if(isBalance(charFreq)) {
					DP[end] = start > 0 ? std::min(DP[end], 1 + DP[start - 1]) : 1;
				}
			}
			
		}
		return DP[N - 1];
	}
};