#include <bits/stdc++.h>


class Solution {
public:
    std::string toGoatLatin(std::string sentence) {
        std::string volv = "aeiouAEIOU";
        std::string res;
        std::stringstream parse(sentence);
        int k = 1;
        std::string tmp;
        while(parse >> tmp) {
            if(volv.find(tmp[0]) != std::string::npos) {
                tmp += "ma";
            } else {
                tmp.push_back(tmp[0]);
                tmp += "ma";
                tmp.erase(0, 1);
            }
            for (int i = 0; i < k; i++)
            {
                tmp += 'a';
            }
            k++;
            res += tmp + ' ';
        }
        res.pop_back();
        return res;
    }
};