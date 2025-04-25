#include <bits/stdc++.h>
const long long mod = 1000 * 1000 * 1000 + 7;
const long long p = 29;
const long long maxn = 1000000+9;
std::unordered_map<long long, int> hash_quant;
std::vector<int> ppow(maxn);
void addHash(std::string hash) {
	std::vector<long long> MyHash(hash.size());
	for (int i = 0; i < hash.size() -1; i++) {
		if(!ppow[i +1]) ppow[i + 1] = (ppow[i] * p) % mod;
      MyHash[i + 1] = (MyHash[i] * p + hash[i]) % mod;
		hash_quant[MyHash[i + 1]]++;
	}
}

int thereISHash(std::string hash) {
	std::vector<long long> MyHashtemp(hash.size() + 1);
	for (int i = 0; i < hash.size(); i++) {
		if(!ppow[i + 1])
			ppow[i + 1] = (ppow[i] * p) % mod;
		MyHashtemp[i + 1] = (MyHashtemp[i] * p + hash[i]) % mod;
	}
	if(hash_quant.count(MyHashtemp[hash.size()]))
		return hash_quant[MyHashtemp[hash.size()]];
	return 0;
}

int main() {
	std::ios_base::sync_with_stdio(0);
   std::cin.tie(0);
   std::cout.tie(0);
	ppow[0] = 1;
	int t;
	std::cin >> t;
	while (t--)
	{
		std::string str;
		std::cin >> str;
		if (str[0] == '+') {
			str.erase(str.begin());
			addHash(str);
		} else {
			str.erase(str.begin());
			std::cout << thereISHash(str);
		}
	}
}