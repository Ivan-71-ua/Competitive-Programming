
#include <bits/stdc++.h>


int main() {
	int a, b;
    char c;
    std::cin>>a>>c>>b;
    while (true) {
        ++b;
        if (b == 60) {
            b = 0;
            ++a;
            if (a == 24) {
                a = 0;
            }
        }
        std::string s;
        s += a / 10 + '0';
        s += a % 10 + '0';
        s += ':';
        s += b / 10 + '0';
        s += b % 10 + '0';
        if (s[0] == s[4] && s[1] == s[3]) {
            std::cout << s << std::endl;
            return 0;
        }
    }
    return false;
}

