#include <bits/stdc++.h>


#include <bits/stdc++.h>

class Solution {
public:
	int getMinSwaps(std::string num, int k) {
		std::string target = num;

		while (k--) {
			std::next_permutation(target.begin(), target.end());
		}

		int res = 0;
		std::string cur = num;

		for (int i = 0; i < cur.size(); i++) {
			if (cur[i] != target[i]) {
				int j = i + 1;
				while (cur[j] != target[i]) {
					j++;
				}
				while (j > i) {
					std::swap(cur[j], cur[j - 1]);
					res++;
					j--;
				}
			}
		}

		return res;
	}
};


int mian() {
	Solution ans;
	ans.getMinSwaps("5489355142", 4);
}