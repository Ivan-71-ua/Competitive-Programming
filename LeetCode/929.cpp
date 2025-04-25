#include <bits/stdc++.h>

class Solution {
public:
   int numUniqueEmails(std::vector<std::string>& emails) {
		std::set<std::string> val;
		for (int i = 0; i < emails.size(); i++)
		{
			std::string s = "";
			bool dog = false, plus = true;
			for (int j = 0; j < emails[i].size(); j++)
			{
				if(dog) {
					s += emails[i][j];
				}else {
					if(plus) {
						if(emails[i][j] == '.') continue;
						if(emails[i][j] == '+')
							plus = false;
						if(emails[i][j] != '.' && emails[i][j] != '+' && emails[i][j] != '@') {
							s += emails[i][j];
						}
						if(emails[i][j] == '@') {
							dog = true;
							s += emails[i][j];
						}
					} else {
						if(emails[i][j] == '@') {
						dog = true;
						s += emails[i][j];
						}
					}
				}
			}
			val.insert(s);
		}
		return val.size();
	}
};

int main() {
	Solution ans;
	std::vector<std::string> emails{"test.email+al+ex@leetcode.com", "test.e.mail+bob.cathy@leetcode.com", "testemail+david@lee.tcode.com"};
	ans.numUniqueEmails(emails);
}