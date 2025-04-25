#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <cmath>
#include <math.h>
#include <string>
#include <time.h>
#include <random>
#include <memory.h>
#include <bitset>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


int main()
{
    ll n, s, mn;
    cin >> n;
    s = 0, mn = 1e18;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        s += x;
        mn = min(mn, x);
    }
    cout << s + (n - 2) * mn << "\n";

    return 0;
}