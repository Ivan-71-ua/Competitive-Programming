
#include <bits/stdc++.h>




class Solution {
	std::unordered_map<std::string, int> has_supplies;
	std::unordered_map<std::string, int> idx_dish;
	bool can_make(int idx_meal, std::vector<std::string>& recipes, std::vector<std::vector<std::string>>& ingredients, std::unordered_set<std::string> &circul) {
		bool can = true;
		if(circul.count(recipes[idx_meal])) {
			return false;
		}
		circul.insert(recipes[idx_meal]);
		for (int i = 0; i < ingredients[idx_meal].size(); i++) {
			std::string cur_ingred = ingredients[idx_meal][i];
			if(has_supplies.count(cur_ingred)){
				continue;
			} else if(idx_dish.count(cur_ingred)) {
				if(can_make(idx_dish[cur_ingred], recipes, ingredients, circul)) {
					has_supplies[cur_ingred] = 1;
				} else {
					can = false;
					break;
				}
			} else {
				can = false;
				break;
			}
		}
		return can;
	}
public:
	std::vector<std::string> findAllRecipes(std::vector<std::string>& recipes, std::vector<std::vector<std::string>>& ingredients, std::vector<std::string>& supplies) {
		for (int i = 0; i < supplies.size(); i++) {
			has_supplies[supplies[i]] = 1;
		}
		for(int i = 0; i < recipes.size(); i++) {
			idx_dish[recipes[i]] = i;
		}
		std::vector<std::string> ans;
		for (int i = 0; i< recipes.size(); i++) {
			std::unordered_set<std::string> circul;
			if(can_make(i, recipes, ingredients, circul)) {
				ans.push_back(recipes[i]);
			}
		}
		return ans;
	}
};