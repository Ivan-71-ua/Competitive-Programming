#include <bits/stdc++.h>



class Solution {
public:
	bool canChange(std::string start, std::string target) {
		int n = start.size();
		int j = 0, i = 0;
		for (; i < n && j < n; )
		{
			while(i < n && start[i] == '_') i++;
			while(j < n && target[j] == '_') j++;
			
			if(i == n && j == n)
				return true;
			if(i == n || j == n)
				return false;

			if(start[i] != target[j])
				return false;
			if(start[i] == 'L' && i < j) {
				return false;
			} 
			if(start[i] == 'R' && i > j) {
				return false;
			}
			i++;
			j++;
		}
		return true;
	}
};


int main() {
	Solution ans;
	ans.canChange("_L__R__R_", "L______RR");
}