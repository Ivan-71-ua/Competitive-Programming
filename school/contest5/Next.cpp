#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int main() {
    std::set<int> ans;
    int n;
    std::cin >> n;
    std::string ask;
    int last = -1;
    for (int i = 0; i < n; i++)
    {
        char what;
        std::cin >> what;
        ask += what;
        int num;
        std::cin >> num;
        if(i > 0 && ask[i-1] == '?' && ask[i] == '+') {
            ans.insert((num + last) % 1000000000);
        } else if(what == '+') {
            ans.insert(num);
        } else if(what == '?') {
            if(ans.lower_bound(num) != ans.end()) {
                int tp = *ans.lower_bound(num);
                std::cout << tp << '\n';
                last = tp;
            } else {
                std::cout << -1 << '\n';
                last = -1;
            }
        }
    }
}