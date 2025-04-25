#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    std::stack<int> maxbn;
    maxbn.push(0);
    for (int i = 0; i < n; i++)
    {
        int k;
        std::cin >> k;
        if(k != 0) {
            maxbn.push(std::max(k, maxbn.top()));
        } else {
            maxbn.pop();
            std::cout << maxbn.top() << '\n';

        }
    }
}