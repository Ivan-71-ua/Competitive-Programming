#include <bits/stdc++.h>


int main() {
    long long n, ans = 0;
    std::vector<long long>cnt(26);
    bool same = false;
    std::string s;

    std::cin >> s;
    n = s.size();

    for(int i=0;i<n;i++){
        cnt[((int)(s[i] - 'a'))]++;
    }

    ans = n * n;

    for(int i=0;i<26;i++){
        ans -= cnt[i] * cnt[i];
        if(cnt[i]>1)
            same = true;
    }

    ans /= 2;
    if(same)
        ans++;
    std::cout << ans << '\n';
    return 0;
}
