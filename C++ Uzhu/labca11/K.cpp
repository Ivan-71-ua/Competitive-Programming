#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
//Rectangular Pasture
const int MAXN = 352;

int n, k;
std::string str;
int prefix[MAXN];
int dp[MAXN][MAXN][MAXN];

int can_win(int l, int r, int uk) {
    int& res = dp[l][r][uk];
    if (res == -1) {
        int total_red = prefix[n - 1];
        int red_left = prefix[r];
        if (l) 
            red_left -= prefix[l - 1];
        int other_red = total_red - red_left - uk;
        if (uk >= k) {
            res = 0;
        } else if (other_red >= k) {
            res = 1;
        } else {
            if (!can_win(l + 1, r, other_red) || !can_win(l, r - 1, other_red)) {
                res = 1;
            } else {
                res = 0;
            }
        }
    }
    return res;
}

int main() {
    fast;
    std::cin >> n >> k;
    std::cin >> str;
    for (int i = 0; i < n; i++) 
        prefix[i] = (str[i] == 'C');
    for (int i = 1; i < n; i++) 
        prefix[i] += prefix[i - 1];
    for (int i = 0; i < MAXN; i++) 
        for (int j = 0; j < MAXN; j++) 
            for (int k = 0; k < MAXN; k++) 
                dp[i][j][k] = -1;
    if (can_win(0, n - 1, 0)) {
        std::cout << "DA" << std::endl;
    } else {
        std::cout << "NE" << std::endl;
    }
}
