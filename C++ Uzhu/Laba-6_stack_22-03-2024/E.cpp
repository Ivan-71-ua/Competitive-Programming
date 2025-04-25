#include <bits/stdc++.h>
#define  int long long

int32_t main() {
    int res = 0;
    std::stack<int> digit;
    std::string tmp;
    while(std::cin >> tmp) {
        if(tmp == "+") {
            int a = digit.top();
            digit.pop();
            int b = digit.top();
            digit.pop();
            digit.push(a + b);
        } else if(tmp == "-") {
            int a = digit.top();
            digit.pop();
            int b = digit.top();
            digit.pop();
            digit.push(b - a);
        } else if(tmp == "*") {
            int a = digit.top();
            digit.pop();
            int b = digit.top();
            digit.pop();
            digit.push(a * b);
        } else if(tmp == "/") {
            int a = digit.top();
            digit.pop();
            int b = digit.top();
            digit.pop();
            digit.push(b / a);
        } else {
            digit.push(stoi(tmp));
        }
    }
    std::cout << digit.top();
}