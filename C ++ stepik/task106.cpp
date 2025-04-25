#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// put a string to lower case for our dictionary
// we can use it as a tag
string to_lower_case(const string& s) {
    string tmp;

    for (int i = 0; i < s.size(); ++i) {
        char ch = s[i];
        if (isupper(ch)) {
            ch = tolower(ch);
        }

        tmp.push_back(ch);
    }

    return tmp;
}

// filling new dictionary
map<string, vector<string>>& fill_dict(map<string, vector<string>>& d, int n) {
    string word;
    string bookmark;

    for (int i = 0; i < n; ++i) {
        cin >> word;
        bookmark = to_lower_case(word);
        d[bookmark].push_back(word);
    }

    return d;
}

void print_dict(const map<string, vector<string>>& dict) {
    for (auto it = dict.begin(); it != dict.end(); ++it) {
        cout << it->first << ": ";
        for (auto&i : it->second) {
            cout << i << ' ';
        }
        cout << endl;
    }
}

// check if a word is in a dictionary
bool in_dict(const vector<string>& dict, const string &word) {
    for (int i = 0; i < dict.size(); ++i) {
        if (word == dict[i]) {
            return true;
        }
    }

    return false;
}

// count accents in a word which are dedicated by upper letters
int count_upper(const string &s) {
    int cnt = 0;

    for (int i = 0; i < s.size(); ++i) {
        if (isupper(s[i])) {
            ++cnt;
        }
    }

    return cnt;
}

// check essay for right accents in words with using a dictionary
int check_work(const map<string, vector<string>>& dict) {
    int mistakes = 0;
    string word;

    while (cin >> word) {
        if (count_upper(word) != 1) {
            ++mistakes;
        }
        else {
            string low_case_word = to_lower_case(word);
            auto it = dict.find(low_case_word);

            if (it != dict.end() && !in_dict(it->second, word)) {
                ++mistakes;
            }
        }
    }

    return mistakes;
}

int main() {
    map<string, vector<string>> dict;
    int n;

    cin >> n;
    dict = fill_dict(dict, n);
    cout << check_work(dict);

    return 0;
}