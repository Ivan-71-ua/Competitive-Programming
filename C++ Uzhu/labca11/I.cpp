#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);



int main() {
    fast;
    std::vector<std::vector<int>> net(1001, std::vector<int>(1001));
    int n, k;
    std::cin >> n >> k;
    while(n--) {
        int a, b, c, d;
        std::cin >> a >> b >> c >> d;
        net[a][b]++;
        net[a][d]--;
        net[c][b]--;
        net[c][d]++;
    }
    int ans = 0;
    for(int i = 0; i < 1000; i++) {
        for(int j = 0; j < 1000; j++) {
            if(i) net[i][j] += net[i-1][j];
            if(j) net[i][j] += net[i][j-1];
            if(i && j) net[i][j] -= net[i-1][j-1];
            if(net[i][j] == k) ans++;
        }
    }
    std::cout << ans;
}