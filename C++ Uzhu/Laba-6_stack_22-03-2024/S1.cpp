#include <iostream>
#include <stack>
#include <string>

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore(); 
    for (int i = 0; i < n; i++) {
        std::string st;
        std::getline(std::cin, st);
        std::stack<char> way;
        bool is = true;
        for (char c : st) {
            if (c == '[' || c == '(') {
                way.push(c);
            } else if (c == ']' || c == ')') {
                if (way.empty()) {
                    is = false;
                    break;
                } else if ((c == ']' && way.top() == '[') || (c == ')' && way.top() == '(')) {
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
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
    }
}
