#include <iostream>
#include <set>

using namespace std;

string toupper(string a) {
    string b = "";
    for (auto c : a)
        b += toupper(c);
    return b; }

int upper(string a) {
    int n = 0;
    for (auto c : a)
        if (c >= 'A' && c <= 'Z')
            n++;
    return n; }

int main() {
    int n;
    string s;
    cin >> n;
    set <string> a, b;
    while (n--) {
        cin >> s;
        a.insert(s);
        b.insert(toupper(s)); }
    n = 0;
    while (cin >> s) {
        if (upper(s) != 1) {
            n++;
            continue; }
        if (a.find(s) != a.end())
            continue;
        if (b.find(toupper(s)) != b.end())
            n++; }
    cout << n;
    return 0; }