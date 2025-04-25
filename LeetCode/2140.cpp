#include <bits/stdc++.h>

class Solution {
long long Max_Point(int k, std::vector<std::vector<int>>& questions, std::vector<long long> &hashing) {
	if(k >= questions.size()) {
		return 0;
		}
	if(hashing[k]) {
		return hashing[k];
		}
	hashing[k] = std::max(Max_Point(k + 1, questions, hashing), questions[k][0] + Max_Point(k + 1 + questions[k][1], questions, hashing));
	return hashing[k];
}
public:
   long long mostPoints(std::vector<std::vector<int>>& questions) {
      std::vector<long long> hashing(questions.size() + 1, 0);
		return Max_Point(0,questions, hashing);
		
	}
};