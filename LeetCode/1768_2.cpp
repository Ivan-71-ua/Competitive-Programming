#include <bits/stdc++.h>


class Solution {
public:
    std::string mergeAlternately(std::string word1, std::string word2)
    {
        int i=0;
        std::string final="";

        while(i < word1.size() && i < word2.size())
            final = final + word1[i] + word2[i++];

        while(i < word1.size())
            final += word1[i++];
        while(i < word2.size())
            final += word2[i++];

        return final;
    }
};