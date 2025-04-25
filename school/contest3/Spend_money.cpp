#include <bits/stdc++.h>


int main() {
	long long res = pow(2, 59);
	std::string st;
	while (res)
	{
		std::cout << "withdraw " << res << std::endl;
		std::cin >> st;
		res /= 2;
	}
   std::cout << "finish "<< res << std::endl;
	return 0;
}
