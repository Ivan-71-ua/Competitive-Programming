#include <bits/stdc++.h>
#define ll long long
#define db double




int main() {
    ll n, k = 0, k1= 0;
    std::cin >> n;
    std::string name = "", name1 = "";
    for (ll i = 0; i < n; i++)
    {
        std::string s;
        std::cin >> s;
        if(name == "") {
            name = name + s;
            k++;
            continue;
        }
        if(s == name) {
            k++;
            continue;
        }
        if(name1 == "") {
            name1 = name1 + s;
            k1++;
            continue;
        }
        if(s == name1) {
            k1++;
            continue;
        }
    }
    if(k > k1) {
        std::cout << name;
    }
    else {
        std::cout << name1;
    }
}