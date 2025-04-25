#include <bits/stdc++.h>

class Solution {
public:
   std::vector<int> twoSum(std::vector<int>& numbers, int target) {
		int L = 0, R = numbers.size() - 1;
		while(numbers[L] + numbers[R] != target) {
			if(numbers[L] + numbers[R] > target) {
				R--;
			} else {
				L++;
			}
		}
		std::vector ans {L + 1, R + 1};
		return ans;
	}
};

int main() {
	Solution ans;
	std::vector<int> numbers{2, 7, 11, 15};
	ans.twoSum(numbers, 9);
}