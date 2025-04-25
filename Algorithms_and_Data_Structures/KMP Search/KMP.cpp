#include <bits/stdc++.h>

std::vector<int> pref_fun(std::string s) {
    int n = s.size();
    std::vector<int> pref(n);
    for (int i = 1; i < n; i++) {
        int j = pref[i -1];
        while(s[i] != s[j] && j > 0) {
            j = pref[j -1];
        }
        if(s[i] == s[j]) j++;
        pref[i] = j;
    }
    return  pref;
}

int serch_KMP(std::string srch, std::string where) {
    std::vector<int> pref_srch = pref_fun(srch);
    int j = 0;
    for (int i = 0; i < where.size(); i++) {
        while(j > 0 && where[i] != srch[j]) {
            j = pref_srch[j -1];
        }
        if(srch[j] == where[i]) {
            j++;
        }
        if(j >= srch.size()) {
            return  i - j + 1;
        }
    }
    return  -1;
}


int main() {
    //std::cout << serch_KMP("I", "IOBBOT POP");
    std::vector<int> ss = pref_fun("ania#aniafjfaniania");
    for (auto n: ss)
    {
        std::cout << n << ' ';
    }
    
}
