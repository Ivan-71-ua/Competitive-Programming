#include <bits/stdc++.h>
const long long mod = 1000 * 1000 * 1000 + 9;
const long long p = 29;

int main() {
	std::ios_base::sync_with_stdio(0);
   std::cin.tie(0);
   std::cout.tie(0);
	std::string hash, revHash;
	std::cin >> hash;
	revHash = hash;
	std::reverse(revHash.begin(), revHash.end());
	std::vector<long long> MyHash(hash.size() + 1);
	std::vector<long long> ReversHash(revHash.size() + 1);
	std::vector<long long> ppow(hash.size() +1);
	ppow[0] = 1;
	for (int i = 0; i < hash.size(); i++) {
		if(!ppow[i +1]) ppow[i + 1] = (ppow[i] * p) % mod;
      MyHash[i + 1] = (MyHash[i] * p + hash[i]) % mod;
	}
	
	for (int i = 0; i < revHash.size(); i++) {
		if(!ppow[i +1]) ppow[i + 1] = (ppow[i] * p) % mod;
      ReversHash[i + 1] = (ReversHash[i] * p + revHash[i]) % mod;
	}
	int t;
	std::cin >> t;
	while (t--)
	{
		int k, k2, l, l2;
		std::cin >> k >> k2;
		l = hash.size() - k2 + 1;
		l2 = hash.size() - k + 1;
		long long hashlr1 = ((MyHash[k2] - MyHash[k - 1] * ppow[k2 - k + 1]) % mod + mod) % mod;
		long long hashlr2 = ((ReversHash[l2] - ReversHash[l - 1] * ppow[l2 - l + 1]) % mod + mod) % mod;
		if(hashlr1 == hashlr2)
			std::cout << '+';
		else {
			std::cout << '-';
		}
	}
}