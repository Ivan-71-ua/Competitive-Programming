#include <bits/stdc++.h>

class Solution {
public:
	std::unordered_map<std::string, std::string> short_long;
	std::string encode(std::string longUrl) {
		std::string temp = "short.com";
		short_long[temp] = longUrl;
		return temp;
	}
   std::string decode(std::string shortUrl) {
      if(short_long.count(shortUrl)) {
			return short_long[shortUrl];
		}
		return "";
	}
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));