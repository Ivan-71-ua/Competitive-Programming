#include <bits/stdc++.h>



class Solution {
public:
	std::string orderlyQueue(std::string s, int k) {
		if(k > 1) {
			std::stable_sort(s.begin(), s.end());
			return s;
		} else {
			std::string mins = s;
			for (int i = 0; i < s.size(); i++)
			{
				s.push_back(s[0]);
				s.erase(s.begin());
				mins = std::min(mins, s);
			}
			return mins;
		}
		return "";
	}
};

int main() {
	Solution ans;
	ans.orderlyQueue("gn", 2);
}