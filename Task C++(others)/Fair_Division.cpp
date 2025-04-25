#include <bits/stdc++.h>
#define ll long long

int main() {
    ll t;
    std::cin >> t;
    while (t--)
    {
        ll k, on = 0, sc = 0;
        std::cin >> k;
        for (int i = 0; i < k; ++i) {
            ll p;
            std::cin >> p;
            if(p == 1) {
                on++;
            }
            else {
                sc++;
            }
        }



        
        
        if(on % 2 == 0 && sc == 0 || sc % 2 == 0 && on == 0 || on % 2 == 0 && sc % 2 == 0) {
            std::cout << "YES\n";
        }
		  else if(on % 2 != 0 && sc == 0 || sc % 2 != 0 && on == 0) {
            std::cout << "NO\n";
		  }
        else if((on +sc * 2) % 2 == 0) {
            std::cout << "YES\n";
        }
        else if(on % 2 != 0 || sc % 2 != 0) {
            std::cout << "NO\n";
		  }
        else {
            std::cout << "NO\n";
        }
    

    }  
}