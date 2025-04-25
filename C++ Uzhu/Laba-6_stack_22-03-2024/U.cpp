#include <bits/stdc++.h>

int main() {
    
    std::string st;
    std::getline(std::cin, st);
    std::stack<char> way;
    bool is = true;
    for (char c : st) {
        if (c == '[' || c == '(' || c == '{') { 
            way.push(c);
        } else if (c == ']' || c == ')' || c == '}') {
            if (way.empty()) {
                is = false;
                break;
            } else if ((c == ']' && way.top() == '[') || (c == ')' && way.top() == '(') || (c == '}' && way.top() == '{')) {
                way.pop();
            } else {
                is = false;
                break;
            }
        }
    }
    if (!way.empty()) {
        is = false;
    }
    if (is) {
        std::cout << "yes\n";
    } else {
        std::cout << "no\n";
    }
}
