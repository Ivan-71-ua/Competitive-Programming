#include <bits/stdc++.h>

class Solution {
public:
	bool isValid(std::string word) {
		if (word.size() < 3)
				return false;

		bool digit = false;
		bool vowel = false;
		bool non_vowel = false;

		for (char &now : word) {
				if (std::isdigit(now)) {
					digit = true;
				} else if (std::isalpha(now)) {
					now = std::tolower(now);
					if (now == 'o' || now == 'a' || now == 'i' || now == 'u' || now == 'e') {
						vowel = true;
					} else {
						non_vowel = true;
					}
				} else {
					return false;
				}
		}

		return vowel && non_vowel;
	}
};

int main() {
	Solution asn;
	asn.isValid("234Adas");

}