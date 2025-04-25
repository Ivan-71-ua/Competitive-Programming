#include <bits/stdc++.h>



class Solution {
public:
    std::vector<std::string> readBinaryWatch(int turnedOn) {
        std::vector<std::string> ans;
        std::vector<int> bits(10);
        for (int i = 9; i >= 10 - turnedOn; i--)
        {
            bits[i] = 1;
        }
        do
        {
            int hour =
                bits[0] * 8 +
                bits[1] * 4 +
                bits[2] * 2 +
                bits[3] * 1;
            int mins =
                bits[4] * 32 +
                bits[5] * 16 +
                bits[6] * 8 +
                bits[7] * 4 +
                bits[8] * 2 +
                bits[9] * 1;
        if(hour < 12 && mins < 60) {
            std::string tp;
            tp += std::to_string(hour) + ':';
            if(mins < 10) {
                tp += '0' + std::to_string(mins);
            } else {
                tp += std::to_string(mins);
            }
            ans.push_back(tp);
        }
        } while (std::next_permutation(bits.begin(), bits.end()));
        return ans;
    }
};

int main() {
    Solution ans;
    ans.readBinaryWatch(1);
}