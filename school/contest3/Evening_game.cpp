#include <bits/stdc++.h>


int main() {
   std::ios_base::sync_with_stdio(0);
   std::cin.tie(0);
   std::cout.tie(0);
	int n;
	std::cin >> n;
	std::vector<int> ans(n, 0);
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			std::cout << "?" << i << " " << j << std::endl;
			char ar;
			std::cin >> ar;
			if (ar == '>')
				ans[i - 1]++;
			else if(ar == '<') {
				ans[j - 1]++;
			}
		} 
	}
	std::cout << '! ';
	for (int i = 0; i < n; i++)
	{
		std::cout << ans[i] + 1 << ' ';
	}
}