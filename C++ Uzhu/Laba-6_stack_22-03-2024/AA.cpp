#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    std::stack<int> maxbn;
    maxbn.push(INT32_MAX);
    for (int i = 0; i < n; i++)
    {
        int k;
        std::cin >> k;
        if(k  == 1) {
            int tmp;
            std::cin >> tmp;
            maxbn.push(std::min(tmp, maxbn.top()));
        } else if(k == 2){
            maxbn.pop();
        } else {
            std::cout << maxbn.top() << '\n';
        }
    }
}