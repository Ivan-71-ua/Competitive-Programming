#include <bits/stdc++.h>

class Solution {
public:
   bool canConstruct(std::string ransomNote, std::string magazine) {
      std::map<char, int> leter_wd;
		for (int i = 0; i < magazine.size(); i++)
		{
			leter_wd[magazine[i]]++;
		}
		for (int i = 0; i < ransomNote.size(); i++)
		{
			if(leter_wd.count(ransomNote[i])) {
				if(leter_wd[ransomNote[i]] > 0) {
					leter_wd[ransomNote[i]]--;
				} else {
					return false;
				}
			} else {
				return false;
			}
		}
		return true;
	}
};