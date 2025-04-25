#include <bits/stdc++.h>

class Solution {
public:
   std::vector<int> replaceElements(std::vector<int>& arr) {
		int n = arr.size(), max = -1;
		std::vector<int> ans(n);
		ans[n - 1] = -1;
		for (int i = n -2, j = n -1; i >= 0 ; i--, j--)
		{
			if(max < arr[j])
				max = arr[j];
			ans[i] = max;
		}
		return ans;
	}
};

int main() {
	Solution ans;
	std::vector<int> arr{400};
	ans.replaceElements(arr);
}