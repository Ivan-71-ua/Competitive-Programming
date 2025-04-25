#include <bits/stdc++.h>





class Solution {
public:
	int maxChunksToSorted(std::vector<int>& arr) {
		int res = 1;
		int maxs = -1;
		for (int i = 0; i < arr.size(); i++)
		{
			maxs = std::max(maxs, arr[i]);
			if(maxs == i)
				res++;
		}
		return res;
	}
};