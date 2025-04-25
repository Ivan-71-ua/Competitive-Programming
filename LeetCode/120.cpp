#include <bits/stdc++.h>

class Solution {
public:
    int minimumTotal(std::vector<std::vector<int>>& triangle) {
        if(triangle.size() == 1)
            return triangle[0][0];
        std::vector<std::vector<int>> dp_tr(triangle.size());
        dp_tr[0] = {triangle[0][0]};
        for (size_t i = 1; i < triangle.size(); i++)
        {
            std::vector<int> tp(triangle[i].size());
            for (size_t j = 0; j < triangle[i].size(); j++)
            {
                if(j == 0) {
                    tp[j] = dp_tr[i - 1][j] + triangle[i][j];
                } else if(j == dp_tr[i - 1].size()) {
                    tp[j] = dp_tr[i - 1][j - 1] + triangle[i][j];
                } else {
                    tp[j] = std::min(dp_tr[i - 1][j] + triangle[i][j], dp_tr[i - 1][j - 1] + triangle[i][j]);
                }
            }
            dp_tr[i] = tp;
        }
        return *std::min_element(dp_tr[dp_tr.size() - 1].begin(), dp_tr[dp_tr.size() - 1].end());
    }
};