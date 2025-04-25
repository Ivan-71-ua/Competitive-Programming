#include <bits/stdc++.h>

class Solution {
public:
    std::vector<int> queryResults(int limit, std::vector<std::vector<int>>& queries) {
        std::unordered_map<int, int> x_color;
        std::unordered_map<int, int> color_count;
        std::unordered_set<int> unique_colors;
        std::vector<int> ans;
        for (const auto& query : queries) {
            int x = query[0];
            int y = query[1];
            if (x_color.find(x) != x_color.end()) {
                int old_color = x_color[x];
                color_count[old_color]--;
                if (color_count[old_color] == 0) {
                    unique_colors.erase(old_color);
                }
            }
            
            x_color[x] = y;
            
            color_count[y]++;
            unique_colors.insert(y);
            ans.push_back(unique_colors.size());
        }
        return ans;
    }
};
