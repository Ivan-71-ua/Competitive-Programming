#include <bits/stdc++.h>


const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
   int romanToInt(std::string s) {
		std::unordered_map<std::string, int> num;
		num["I"] = 1, num["V"] = 5, num["X"] = 10, num["L"] = 50, num["C"] = 100,
		num["D"] = 500, num["M"] = 1000, num["IV"] = 4, num["IX"] = 9, num["XL"] = 40,
		num["XC"] = 90, num["CD"] = 400, num["CM"] = 900;
		int ans = 0;
		for (int i = 0; i < s.size(); i++)
		{
			std::string k = "", k2 = "";
			k += s[i];
			k2 += s[i];
			k2 += s[i + 1];
			if(num.count(k2)) {
				ans += num[k2];
				i++;
			}
			else {
				ans += num[k];
			}
		}
		return ans;
	}
};

int main() {
	Solution ans;
	ans.romanToInt("MCMXCIV");
}