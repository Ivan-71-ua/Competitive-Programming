#include <bits/stdc++.h>




class Solution {
public:
	std::string dayOfTheWeek(int day, int month, int year) {
		std::vector<int> month_day{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		std::vector<std::string> day_week{"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
		int days = 0;
		for (int i = 1971; i < year; i++)
		{
			days += 365;
			if((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) {
				days++;
			}
		}
		
		for (int i = 0; i < month - 1; i++)
		{
			days += month_day[i];
			if(i == 1 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
				days++;
			}
		}
		days += day;
		int start_day = 4;
		days += start_day;
		days %= 7;
		return day_week[days];
	}
};