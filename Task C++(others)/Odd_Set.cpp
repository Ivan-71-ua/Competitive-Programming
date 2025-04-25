	#include <bits/stdc++.h>

	int main() {
		int t;
		std::cin >> t;
		while (t--)
		{
			int n;
			std::cin >> n;
			int ans = 0;
			for (int i = 0; i < n * 2; i++)
			{
				int k;
				std::cin >> k;
				if(k % 2 == 1)
					ans++;
			}
			if(ans == n)
				std::cout << "Yes\n";
			else
				std::cout << "No\n";
		}
		
	}