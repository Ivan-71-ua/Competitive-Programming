#include <bits/stdc++.h>

int main() {
    int t;
    std::cin >> t;
    while(t--) {
        int n;
        std::cin >> n;
        std::vector<int> nums(n);
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            std::cin >> nums[i];
            sum += nums[i];
        }
        std::vector<int> res;
        while(sum && res.size() < 41) {
            int k = (sum + n - 1) / n;
            res.push_back(k);
            int tmp = 0;
            for (int i = 0; i < n; i++)
            {
                nums[i] = abs(nums[i] - k);
                tmp += nums[i];
            }
            sum = tmp;
        }
        if(res.size() < 41) {
            std::cout << res.size() << '\n';
            for (auto now: res)
            {
                std::cout << now << ' ';
            }
        } else {
            std::cout << -1;
        }
        std::cout << '\n';
    }
}