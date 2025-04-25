#include <bits/stdc++.h>

class Solution {
public:
   int findSpecialInteger(std::vector<int>& arr) {
		int num = -1, cout = -1;
		for (int i = 0; i < arr.size(); )
		{
			int k = std::count(arr.begin(), arr.end(), arr[i]);
			if(k > cout) {
				cout = k;
				num = arr[i];
			}
			i += k;
		}
		return num;
	}
};

int main() {
	Solution ans;
	std::vector<int> nums{1,1};
	std::cout << ans.findSpecialInteger(nums);
}