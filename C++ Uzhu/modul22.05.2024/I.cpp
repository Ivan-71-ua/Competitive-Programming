#include <bits/stdc++.h>
//#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
//#define int long long 

int main() {
    //fast;
    int n, target;
    std::cin >> n >> target;
    std::vector<int> numbers(n);
    std::unordered_set<int> num;

    for (int i = 0; i < n; i++) {
        std::cin >> numbers[i];
        num.insert(numbers[i]);
    }

    for (int i = 0; i < n; i++) {
        if (num.count(numbers[i] + target)) {
            std::cout << "Yes\n";
            return 0;
        }
    }
    std::cout << "No\n";
    return 0;
}
