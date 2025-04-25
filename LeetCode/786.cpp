#include <bits/stdc++.h>

class Solution {
public:
	std::vector<int> kthSmallestPrimeFraction(std::vector<int>& arr, int k) {
		std::vector<std::pair<double, std::vector<int>>> res;
		for (int i = 0; i < arr.size(); i++)
		{
			for (int j = i + 1; j < arr.size(); j++)
			{
				res.push_back({(double)arr[i] / arr[j], {arr[i], arr[j]}});
			}
		}
		std::stable_sort(res.begin(), res.end());
		return res[k -1].second;
	}
};


int main() {
	Solution ans;
	std::vector<int> ss{1, 7};
	ans.kthSmallestPrimeFraction(ss, 1);
}