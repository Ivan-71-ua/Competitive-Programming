#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

const long long mod1 = 1000 * 1000 * 1000 + 9;
const long long mod2 = 1000 * 1000 * 1000 + 7;
const long long p1 = 29;
const long long p2 = 31;
const long long maxn = 10000+9;
long long ppow1[maxn], ppow2[maxn];
long long hash1[maxn], hash2[maxn];


int main() { 
    string s;
    cin >> s;
    ppow1[0] = ppow2[0] = 1;
    for (int i = 0; i < s.size(); i++) {
        ppow1[i + 1] = (ppow1[i] * p1) % mod1;
        ppow2[i + 1] = (ppow2[i] * p2) % mod2;
        hash1[i + 1] = (hash1[i] * p1 + s[i]) % mod1; //s[i] - 'a' + 1
        hash1[i + 1] = (hash1[i] * p2 + s[i]) % mod2;
    }
    int l, r;
    cin >> l >> r;
    long long hashlr1 = ((hash1[r] - hash1[l - 1] * ppow1[r - l + 1]) % mod1 + mod1) % mod1;
    long long hashlr2 = ((hash2[r] - hash2[l - 1] * ppow2[r - l + 1]) % mod2 + mod2) % mod2;
}