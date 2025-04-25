#include <iostream>
#include <vector>
#include <string>
using namespace std;

string decodeWord(int code) {
    string word = "";
    while (code > 0) {
        char letter = 'a' + ((code - 1) % 26);
        word = letter + word;
        code = (code - 1) / 26;
    }
    return word;
}

string findMinWord(int code) {
   
    string minWord = "zzz";
    for (int i = 1; i <= 26; ++i) {
        for (int j = 1; j <= 26; ++j) {
            for (int k = 1; k <= 26; ++k) {
                if (i + j + k == code) {
                    string word = string(1, 'a' + i - 1) + string(1, 'a' + j - 1) + string(1, 'a' + k - 1);
                    if (word < minWord) {
                        minWord = word;
                    }
                }
            }
        }
    }
    return minWord;
}

int main() {
   int t;
   cin >> t;

   for (int i = 0; i < t; ++i) {
      int code;
        cin >> code;
        string minWord = findMinWord(code);
        cout << minWord << endl;
    }
}
