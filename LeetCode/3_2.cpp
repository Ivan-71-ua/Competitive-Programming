
#include <bits/stdc++.h>


class Solution {
public:
	int lengthOfLongestSubstring(std::string s) {
		std::vector<int> hash(256, -1);
		int n = s.length();
		int l = 0;
		int r = 0;
		int maxlen = 0;
		while(r < n){
			//checking whether it is present in the hash map or not
			if(hash[s[r]] != -1){
				if(hash[s[r]] >= l){  //it is within the range between l and r
					l = hash[s[r]] + 1;
				}
			}
			int len = r - l + 1;
			maxlen = std::max(len, maxlen);
			hash[s[r]] = r;
			r++;
		}
		return maxlen;
	}
};