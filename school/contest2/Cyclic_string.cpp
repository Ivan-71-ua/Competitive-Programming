#include <bits/stdc++.h>


int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    std::string text;
    std::cin >> text;

    //text += "#" + text;
    std::vector <int> pip(text.size(), 0);
    for (int i = 1; i < text.size(); i++) {
        int j = pip[i - 1];
        while (j > 0 && text[i] != text[j]) {
            j = pip[j - 1];
        }
        if(text[i] == text[j]) {
            j++;
            pip[i] = j;
        }
    }
    std::cout << text.size() - pip[text.size() -1];
}
