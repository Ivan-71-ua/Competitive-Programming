
#include <bits/stdc++.h>


class Solution {
public:
	std::string mostCommonWord(std::string paragraph, std::vector<std::string>& banned) {
		std::unordered_map<std::string, int> ban;
		std::unordered_map<std::string, int> can_used;
		for (auto now : banned)
		{
			ban[now]++;
		}
		std::transform(paragraph.begin(), paragraph.end(), paragraph.begin(), ::tolower);
		for (char c : paragraph) {
			if (ispunct(c)) {
				c = ' ';
			}
		}
		std::stringstream parse(paragraph);
		std::string token;
		std::string ans  = "0";
		while (parse >> token)
		{
			if(!ban[token]) {
				can_used[token]++;
				if(ans == "0") {
					ans = token;
				} else {
					if(can_used[token] > can_used[ans]) {
						ans = token;
					}
				}
			}
		}
		return ans;
	}
};

int main() {
	Solution ans;
	std::vector<std::string> ss{"hit"};
	ans.mostCommonWord("Bob hit a ball, the hit BALL flew far after it was hit.", ss);
}