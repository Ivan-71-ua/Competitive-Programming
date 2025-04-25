#include <bits/stdc++.h>


int main () {
	int tp;
	int k = 1;
	while(std::cin >> tp && tp != 0) {
		std::vector<std::string> box;
		std::vector<std::string> box_sort;
		int res = 0;
		for(int i =0; i < tp; i++) {
				std::string st;
				std::cin >> st;
				box.push_back(st);
				box_sort.push_back(st);
		}
		std::sort(box_sort.begin(), box_sort.end());
		for (int i = 0; i < box.size(); i++)
		{
				int k = std::find(box_sort.begin(), box_sort.end(), box[i]) - box_sort.begin();
				res += abs(i - k);
		}
		std::cout << "Site " << k << ": " << res << '\n';
		k++;
	}
}