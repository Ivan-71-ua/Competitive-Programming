#include <bits/stdc++.h>


int main() {
	int n;
	std::cin >> n;
	std::unordered_map<std::string, int> list;
	for (int i = 0; i < n; i++)
	{
		std::string s;
		std::cin >> s;
		list[s]++;
	}
	bool is = false;
	for (auto now: list)
	{
		if(now.second > n - now.second){
			is = true;
			std::cout << now.first;
		}
	}
	if(!is) {
		std::cout << "NONE";
	}
}