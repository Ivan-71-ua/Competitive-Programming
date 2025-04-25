#include <bits/stdc++.h>



class Solution {
public:
	std::vector<int> distributeCandies(int candies, int num_people) {
		std::vector<int> ans(num_people);
		int i = 0;
		int k = 0;
		while (candies > 0)
		{
			int tmp;
			if(candies - ((i % num_people) + 1 + (k * num_people)) > 0) {
				candies -= (i % num_people) + 1 + (k * num_people);
				tmp = (i % num_people) + 1 + (k * num_people);
			} else {
				tmp = candies;
				candies = 0;
			}
			ans[i % num_people] += tmp;
			if((i + 1) % num_people == 0)
				k++;
			i++;
		}
		return ans;
	}
};

int main() {
	Solution ans;
	ans.distributeCandies(10, 3);
}