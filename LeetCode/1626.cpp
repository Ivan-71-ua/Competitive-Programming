#include <bits/stdc++.h>

class Solution {
public:
   int bestTeamScore(std::vector<int>& scores, std::vector<int>& ages) {
      std::multiset<std::pair<int, int>> sc_ag;
      for (int i = 0; i < scores.size(); i++)
      {
         sc_ag.insert({ages[i], scores[i]});
      }
      std::vector<int> list_ball;
      for(auto now : sc_ag) {
         list_ball.push_back(now.second);
      }
      std::vector<int> pref(scores.size());
      for (int i = 0; i < scores.size(); i++)
      {
         pref[i] = list_ball[i];
         int k = i - 1;
         while(k >= 0) {
            if(list_ball[k] <= list_ball[i] ) {
               pref[i] = std::max(pref[i], list_ball[i] + pref[k]);
            }
            k--;
         }
      }
      return *std::max_element(pref.begin(), pref.end());
   }
};

int main() {
   Solution ans;
   std::vector<int> ss {4,5,6,5};
   std::vector<int> tt {2,1,2,1};
   ans.bestTeamScore(ss, tt);
}