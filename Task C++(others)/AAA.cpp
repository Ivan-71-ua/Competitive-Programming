#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string restoreString(int n, const vector<int>& a) {
    string s(n, ' ');
    vector<int> lastSeen(26, -1);

    for (int i = 0; i < n; ++i) {
        s[i] = char('a' + lastSeen[a[i]] + 1);
        lastSeen[a[i]] = i;
    }

    return s;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int j = 0; j < n; ++j) {
            cin >> a[j];
        }

        string result = restoreString(n, a);
        cout << result << endl;
    }

    return 0;
}