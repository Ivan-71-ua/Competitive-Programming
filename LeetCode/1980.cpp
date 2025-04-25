#include <bits/stdc++.h>




class Solution {
public:
	std::string findDifferentBinaryString(std::vector<std::string>& nums) {
		std::set<long long> num;
		for (int i = 0; i < nums.size(); i++)
		{
			long long tmp = 0;
			for (int j = nums.size() - 1; j >= 0; j--)
			{
				tmp += (nums[i][j] - '0') * (1 << (nums[i].size() - j - 1));
			}
			num.insert(tmp);
		}
		long long fn = 1 << nums[0].size() + 1;
		long long res = -1;
		for (long long i = 0; i < fn; i++)
		{
			if(!num.count(i)) {
				res = i;
				break;
			}
		}
		std::string ans;
		std::bitset<64> bits(res);
		for (int i = nums[0].size() -1; i >= 0; i--)
		{
			if(bits[i]) {
				ans.push_back('1');
			} else {
				ans.push_back('0');
			}
		}
		return ans;
	}
};


int main() {
	Solution ans;
	std::vector<std::string> ss{"00", "01"};
	ans.findDifferentBinaryString(ss);
}