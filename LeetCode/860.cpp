#include <bits/stdc++.h>


class Solution {
public:
	bool lemonadeChange(std::vector<int>& bills) {
		//std::stable_sort(bills.begin(), bills.end());
		//if(bills[0]== 10 || bills[0] == 20)
			//return false;
		int five = 0;
		int ten = 0;
		for (int i = 0; i < bills.size(); i++)
		{
			if(bills[i] == 5)
				five++;
			else if(bills[i] == 10) {
				if(five < 1)
					return false;
				else {
					five--;
					ten++;
				}
			} else if(bills[i] == 20) {
				if(five > 0 && ten > 0) {
					five--;
					ten--;
				} else if(five > 2) {
					five -= 3;
				} else {
					return false;
				}
			}
		}
		return true;
	}
};

int main() {
	Solution ans;
	std::vector<int> ss{5, 5, 10, 20, 5, 5, 5, 5, 5, 5, 5, 5, 5, 10, 5, 5, 20, 5, 20, 5};
	ans.lemonadeChange(ss);
}