#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define int long long


int32_t main() {
	fast;
	std::string song;
	std::getline(std::cin, song);
	std::set<std::string> diferes;
	std::stringstream parse(song);
	std::string word;
	while(parse >> word) {
		for (int i = 0; i < word.size(); i++) {
			if(word[i] >= 'A' && word[i] <= 'Z') {
				word[i] = 'a' + (word[i] - 'A');
			}
		}
		diferes.insert(word);
	}
	std::cout << diferes.size();
}
