#include <bits/stdc++.h>


class Solution {
public:
   int minSwaps(std::string s) {
		if(s.empty())
			return 0;
		int maxs = 0, temp =0;
		for (int i = 0; i < s.size(); i++)
		{
			if(s[i] == ']')
				temp++;
			if(s[i] == '[')
				temp--;
			maxs = std::max(maxs, temp);
		}
		return (maxs + 1) / 2;
	}
};

int main() {
	Solution ans;
	ans.minSwaps("]]][[[");
}
