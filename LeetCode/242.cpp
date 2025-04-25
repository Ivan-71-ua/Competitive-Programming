#include <bits/stdc++.h>


class Solution {
public:
   bool isAnagram(std::string s, std::string t) {
		std::sort(s.begin(), s.end());
		std::sort(t.begin(), t.end());
		if(s != t) {
			return false;
		}
		return true;
	}
};

int main() {
	Solution ans;
	std::string s = "anagram", s1 = "nagaram";
	std::cout << ans.isAnagram(s, s1);
}