#include <bits/stdc++.h>

int main() {
    
    std::string st;
    std::getline(std::cin, st);
    std::stack<char> way;
    bool is = true;
    for (char c : st) {
        if (c == '(' ) { 
            way.push(c);
        } else if ( c == ')' ) {
            if (way.empty()) {
                is = false;
                break;
            } else if ( (c == ')' && way.top() == '(')) {
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
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}
