#include <bits/stdc++.h>





class Solution {
public:
	int countGoodTriplets(std::vector<int>& arr, int a, int b, int c) {
		int res = 0;
		for (int i = 0; i < arr.size(); i++) {
			for (int j = i + 1; j < arr.size(); j++) {
				if(std::abs(arr[i] - arr[j]) <= a) {
					for (int k = j + 1; j < arr.size(); k++) {
						if(std::abs(arr[j] - arr[k]) <= b && std::abs(arr[i] - arr[k]) <= c) {
							res++;
						}
					}
				}
			}
		}
		return res;
	}
};