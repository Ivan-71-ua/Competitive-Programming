#include <bits/stdc++.h>


	class Solution {
	public:
		bool doesValidArrayExist(std::vector<int>& derived) {
			int is = 0;
			for(int &v : derived) {
				is ^= v;
			}
			return is == 0;
		}
	};