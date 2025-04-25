#include <bits/stdc++.h>





class Solution {
public:
	bool checkPowersOfThree(int n) {
		long long pows = std::pow(3, 15);
		while(pows > 0 && n > 0) {
			if(pows <= n) {
				n -= pows;
			}
			pows /= 3;
		}
		return n == 0;
	}

	std::vector<std::vector<int>> logest(std::vector<int> arr) {
		std::vector<std::vector<int>> ans{{}};
		std::vector<int> cur{arr[0]};
		for (int i = 1; i < arr.size(); i++) {
			if(abs(arr[i]) <= cur.back()) {
				if(cur.size() > ans.back().size()) {
					ans.clear();
					ans.push_back(cur);
				} else if(cur.size() == ans.back().size()) {
					ans.push_back(cur);
				}
				cur.clear();
			}
			cur.push_back(arr[i]);
		}
		if(cur.size() > ans.back().size()) {
			ans.clear();
			ans.push_back(cur);
		} else if(cur.size() == ans.back().size()) {
			ans.push_back(cur);
		}
		for(auto k: ans) {
			std::cout << "PDF: ";
			for(auto r : k) {
				std::cout << r << " ";
			}
			std::cout << '\n';
		}
		return ans;
	}
};


int main() {
	Solution ans;
	std::vector<int> ss{-5, -4,-3};
	ans.logest(ss);
}