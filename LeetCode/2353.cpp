#include <bits/stdc++.h>
struct cmp
{
   bool operator()(std::pair<int, std::string> a, std::pair<int, std::string> b) const {
      if(a.first > b.first)
         return 1;
      if(a.first < b.first)
         return 0;
      return (a.second < b.second);
   }
};



class FoodRatings {
public:
   std::unordered_map<std::string, std::set<std::pair<int, std::string>, cmp>> s;\
   std::unordered_map<std::string, std::pair<std::string, int>> m;

   FoodRatings(std::vector<std::string>& foods, std::vector<std::string>& cuisines, std::vector<int>& ratings) {
      int n = foods.size();
      for (int i = 0; i < n; i++)
      {
         m[foods[i]] = {cuisines[i], ratings[i]};
         s[cuisines[i]].insert({ratings[i], foods[i]});
      }
      
   }
   void changeRating(std::string food, int newRating) {
      std::string cuisine = m[food].first;
      int oldRAting = m[food].second;
      s[cuisine].erase({oldRAting, food});

      m[food] = {cuisine, newRating};
      s[cuisine].insert({newRating, food});
   }
   
   std::string highestRated(std::string cuisine) {
      return (*s[cuisine].begin()).second;
   }
};