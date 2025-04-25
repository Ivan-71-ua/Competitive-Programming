#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll optimized_solution(ll n) {
    ll result = 0;
    for (ll i = 1; i <= n;) {
        ll v = n / i;
        ll next = n / v + 1;
        result += v * (next - i);
        i = next;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        cout << optimized_solution(n) << "\n";
    }

    return 0;
}
