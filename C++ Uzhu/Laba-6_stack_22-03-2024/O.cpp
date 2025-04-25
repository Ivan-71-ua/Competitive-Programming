#include <bits/stdc++.h>


int main() {
	std::vector<int> tmp;
	std::unordered_map<int, int> quantity;
	std::string str;
	while (std::cin >> str) {
		if(str == "push") {
			int n;
			std::cin >> n;
			quantity[n]++;
			tmp.push_back(n);
		} else {
			int size = 0;
			int id = -1;
			for (int i = tmp.size() -1; i >= 0; i--)
			{
				if(quantity.count(tmp[i])) {
					if(quantity[tmp[i]] > size) {
						id = i;
					}
				}
			}
			std::cout << tmp[id] << '\n';
			quantity[tmp[id]]--;
			if(id == tmp.size() -1) {
				tmp.pop_back();
			} else {
				tmp.erase(tmp.begin() + id);
			}
		}
	}
}