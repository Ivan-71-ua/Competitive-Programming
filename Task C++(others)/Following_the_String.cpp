#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);


int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++)
    {
        int k;
        std::cin >> k;
        std::string ans;
        std::map<char, int> alf_quant;
        char tp = 'a';
        for (int j = 0; j < k; j++)
        {
            int pip;
            std::cin >> pip;
            if(pip == 0) {
                ans += tp;
                alf_quant[tp]++;
                tp++;
            } else {
					for (auto it = alf_quant.begin(); it != alf_quant.end(); it++)
					{
						if (it->second == pip)
						{
							ans += it->first;
							it->second++;
							break;
						}
                }
            }
        }
        std::cout << ans << '\n';
    }
}