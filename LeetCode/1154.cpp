#include <bits/stdc++.h>


class Solution {
public:
	int dayOfYear(std::string date) {
		int year = std::stoi(date.substr(0, 4));
		int month = std::stoi(date.substr(5, 2));
		int day = std::stoi(date.substr(8, 2));
		int ans = 0;
		std::vector<int> day_of_month{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		for (int i = 1; i < month; i++)
		{
			ans += day_of_month[i];
			if(i == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 100 == 0 && year % 400 == 0)))
				ans++;
		}
		ans += day;
		return ans;
	}
};

int main() {
	Solution ans;
	ans.dayOfYear("1900-05-02");
}