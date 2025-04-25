#include <bits/stdc++.h>

class Solution {
public:
	std::string dayOfTheWeek(int day, int month, int year) {
		std::tm time_in = {0, 0, 0, day, month - 1, year - 1900}; 
		
		std::mktime(&time_in); 
		
		std::string days_of_week[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
		
		return days_of_week[time_in.tm_wday]; 
	}
};