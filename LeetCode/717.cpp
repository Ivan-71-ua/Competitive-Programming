#include <bits/stdc++.h>


class Solution {
public:
	bool isOneBitCharacter(std::vector<int>& bits) {
		for (int i = 0; i < bits.size(); i++)
		{
			if(bits[i] == 1) {
				i++;
				if(i == bits.size() -1)
					return false;
			}
		}
		return true;
	}
};