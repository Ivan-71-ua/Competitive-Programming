#include <bits/stdc++.h>

	class Solution {
	public:
		int numSubseq(std::vector<int>& nums, int target) {
			std::sort(nums.begin(), nums.end());
			long long res = 0;
			long long mod = 1000000000 + 7;
			int r = nums.size() - 1;
			int l = 0;
			while (l <= r) 
			{
				if(nums[l] + nums[r] > target) {
					r--;
				} else {
					res = (res + fastPower(2, r - l, mod)) % mod;
					l++;
				}
			}
			return res;
		}
		int fastPower(int a, int b, int mod) {
         long long ans = 1;
         long long base = a;
         while (b != 0) {
            if (b % 2 == 1) {
               ans = (ans * base) % mod;
            }
         	base = (base * base) % mod;
         	b /= 2;
      	}
      return ans;
   	}
	};

int main() {
	Solution ans;
	std::vector<int> ss{1};
	ans.numSubseq(ss, 1);
}