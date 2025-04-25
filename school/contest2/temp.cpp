#include <bits/stdc++.h>

std::string preprocess(const std::string& s) {
    std::string result = "#";
    for (char c : s) {
        result += c;
        result += "#";
    }
    return result;
}

int manacher(const std::string& s) {
    std::string str = preprocess(s);
    int n = str.length();

    std::vector<int> p(n, 0);
    int center = 0, right = 0;
    int totalPalindromes = 0;

    for (int i = 1; i < n - 1; ++i) {
        int mirror = 2 * center - i;

        if (i < right) {
            p[i] = std::min(right - i, p[mirror]);
        }

        while (str[i + (1 + p[i])] == str[i - (1 + p[i])]) {
            p[i]++;
        }

        if (i + p[i] > right) {
            center = i;
            right = i + p[i];
        }

        totalPalindromes += (p[i] + 1) / 2;
    }

    return totalPalindromes;
}

int main() {
   std::string str;
   std::cin >> str;
   int ans = manacher(str);
   std::cout <<  ans;
}
