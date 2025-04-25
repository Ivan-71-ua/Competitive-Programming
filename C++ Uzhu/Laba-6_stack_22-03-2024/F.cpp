#include <bits/stdc++.h>



int main() {
    std::stack<std::pair<char, int>> ch;
    int res = 0;
    std::string st;
    std::cin >> st;
    ch.push({')', -1});
    for (int i = 0; i < st.size(); i++)
    {
        if(st[i] == '(') {
            ch.push({'(', i});
        } else {
            if(!st.empty() && ch.top().first == '(') {
                ch.pop();
                res = std::max(res, (i - ch.top().second));

            } else {
                ch.push({')', i});
            }
        }
    }
    std::cout << res;
}