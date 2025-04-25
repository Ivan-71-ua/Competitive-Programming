#include <bits/stdc++.h>
const long long mod = 1000 * 1000 * 1000 + 7;
const long long p = 29;

int main() {
   std::ios_base::sync_with_stdio(0);
   std::cin.tie(0);
   std::cout.tie(0);
	int t;
	std::cin >> t;
	while (t--)
	{
		std::string st, st2X;
		int min = -1;
		std::cin >> st;
		st2X = st;
		st2X += st;
		std::vector<long long> MyHash(st2X.size() + 1);
		std::vector<long long> ppow(st2X.size() +1);
		ppow[0] = 1;
		for (int i = 0; i < st2X.size(); i++) {
			if(!ppow[i +1]) ppow[i + 1] = (ppow[i] * p) % mod;
			MyHash[i + 1] = (MyHash[i] * p + st2X[i]) % mod;
		}
		for (int i = 0, j = 1; j < st.size(); i++, j++)
		{
			long long hashlr1, hashlr2;
			for (int k = i, c = j; k < i + st.size(); i++, j++)
			{
				if(i > 0) {
					long long hashlr1 = ((MyHash[k] - MyHash[i - 1] * ppow[k - i + 1]) % mod + mod) % mod;
				} else {
					long long hashlr1 = MyHash[k];
				}
				long long hashlr2 = ((MyHash[c] - MyHash[j - 1] * ppow[c - j + 1]) % mod + mod) % mod;
				if(hashlr1 > hashlr2) {
					min = i;
				} else {
					min = j;
				}
			}
		}
		std::cout << st2X.substr(min - 1, st.size()) << '\n';
	}
}
