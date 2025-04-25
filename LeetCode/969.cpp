#include <bits/stdc++.h>



class Solution {
	int lastIdx(std::vector<int>& arr, int lenght) {
		int res = 0;
		for (int i = 1; i <= lenght; i++) {
			if(arr[res] < arr[i])
				res = i;
		}
		return res;
	}
	void revers(std::vector<int>& arr, int end) {
		int st = 0;
		while(st < end) {
			std::swap(arr[st++], arr[end--]);
		}
	}
public:
	std::vector<int> pancakeSort(std::vector<int>& arr) {
		std::vector<int> res;
		int n = arr.size();
		for (int i = n - 1; i > -1; i--) {
			int cur_m = lastIdx(arr, i);
			if(cur_m != i) {
				res.push_back(cur_m + 1);
				res.push_back(i + 1);
				revers(arr, cur_m);
				revers(arr, i);
			}
		}
		return res;
	}
};


int main() {
	std::vector<int> ss{3, 2, 4, 1};
	Solution ans;
	ans.pancakeSort(ss);
}