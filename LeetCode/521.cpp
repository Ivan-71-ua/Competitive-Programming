#include <bits/stdc++.h>

class Solution {
public:
    int findLUSlength(std::string a, std::string b) {
        if(a == b)
            return -1;
        return std::max(a.size(), b.size());
    }
};