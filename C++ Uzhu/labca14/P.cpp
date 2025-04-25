#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define int long long

int32_t main() {
	fast;
	int n, m, k;
	std::cin >> n >> m >> k;
	std::vector<int> want(n);
	std::vector<int> is(m);
	for (int i = 0; i < n; i++)
	{
		std::cin >> want[i];
    }
    for (int i = 0; i < m; i++)
    {
        std::cin >> is[i];
    }
    std::stable_sort(is.begin(), is.end());
    std::stable_sort(want.begin(), want.end());
    int i = 0;
    int j = 0;
    int l = 0;
    while(i < n || j < m) {
        if(is[i] <= want[j] + k && is[i] >= want[j] - k) {
            i++;
            j++;
            l++;
        } else if(is[i] < want[j] - k){
            i++;
        } else if(is[i] > want[j] + k) {
            j++;
        }
    }
    std::cout << l;
}