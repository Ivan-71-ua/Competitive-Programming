#include <bits/stdc++.h>





class Solution {
public:
	int countTriplets(std::vector<int>& arr) {
		std::vector<int> pref(arr.size() +1);
		int res = 0;

		for (int i = 0; i < arr.size(); i++)
		{
			pref[i + 1] = pref[i] ^ arr[i];
		}
		for (int i = 0; i < arr.size(); i++)
		{
			for (int k = i + 1; k < arr.size(); k++)
			{
				if(pref[i] == pref[k +1]) {
					res += k - i;
				}
			}
		}
		return res;
	}
};