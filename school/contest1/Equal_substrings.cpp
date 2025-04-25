#include <bits/stdc++.h>
const long long mod = 1000 * 1000 * 1000 + 9;
const long long p = 29;

int main() {
	std::ios_base::sync_with_stdio(0);
   std::cin.tie(0);
   std::cout.tie(0);
	std::string hash;
	std::cin >> hash;
	std::vector<long long> MyHash(hash.size() + 1);
	std::vector<long long> ppow(hash.size() +1);
	ppow[0] = 1;
	for (int i = 0; i < hash.size(); i++) {
		if(!ppow[i +1]) ppow[i + 1] = (ppow[i] * p) % mod;
      MyHash[i + 1] = (MyHash[i] * p + hash[i]) % mod;
	}
	int t;
	std::cin >> t;
	while (t--)
	{
		int k, k2, l, l2;
		std::cin >> k >> k2 >> l >> l2;
		long long hashlr1 = ((MyHash[k2] - MyHash[k - 1] * ppow[k2 - k + 1]) % mod + mod) % mod;
		long long hashlr2 = ((MyHash[l2] - MyHash[l - 1] * ppow[l2 - l + 1]) % mod + mod) % mod;
		if(hashlr1 == hashlr2)
			std::cout << '+' << '\n';
		else {
			std::cout << '-' << '\n';
		}
	}
}