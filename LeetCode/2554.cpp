#include <bits/stdc++.h>



class Solution {
public:
	int maxCount(std::vector<int>& banned, int n, int maxSum) {
		std::stable_sort(banned.begin(), banned.end());
		int res = 0;
		long long cur_s = 0;
		int j = 1;
		bool full = false;
		for (int i = 0; i < banned.size() && j <= n; i++)
		{
			if(full) break;
			for (int k = j; k < banned[i] && k <= n; k++) {
				
				if(cur_s + k <= maxSum) {
					cur_s += k;
					res++;
				} else {
					full = true;
					break;
				}
			}
			j = banned[i] + 1;
		}
		while(j <= n) {
			if(cur_s + j <= maxSum) {
				cur_s += j;
				res++;
			} else {
				break;
			}
			j++;
		}
		return res;
	}
};


int main() {
	Solution ans;
	std::vector<int> ss{176, 36, 104, 125, 188, 152, 101, 47, 51, 65, 39, 174, 29, 55, 13, 138, 79, 81, 175, 178, 42, 108, 24, 80, 183, 190, 123, 20, 139, 22, 140, 62, 58, 137, 68, 148, 172, 76, 173, 189, 151, 186, 153, 57, 142, 105, 133, 114, 165, 118, 56, 59, 124, 82, 49, 94, 8, 146, 109, 14, 85, 44, 60, 181, 95, 23, 150, 97, 28, 182, 157, 46, 160, 155, 12, 67, 135, 117, 2, 25, 74, 91, 71, 98, 127, 120, 130, 107, 168, 18, 69, 110, 61, 147, 145, 38};
	ans.maxCount(ss, 3016, 240);
}