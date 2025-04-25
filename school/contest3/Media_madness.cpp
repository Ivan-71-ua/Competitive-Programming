#include <bits/stdc++.h>


int main() {
   std::ios_base::sync_with_stdio(0);
   std::cin.tie(0);
   std::cout.tie(0);
	int n;
	std::cin >> n;
	std::vector<int> ans;
	for (int i = 1; i <= n; i++)
	{
		std::cout << "?" << i << std::endl;
		int k;
		std::cin >> k;
		ans.push_back(k);
	}
	std::cout << "!";
	for (int i = 0; i < ans.size(); i++)
	{
		std::cout << ans[i] << ' ';
	}
	
}
