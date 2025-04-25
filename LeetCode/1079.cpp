#include <bits/stdc++.h>



class Solution {
public:
	std::map<int, int> used;
	std::set<std::string> count;
	std::string res;
	void build_mult(std::string st) {
		for (int i = 0; i < st.size(); i++)
		{
			if(!used[i]) {
				res.push_back(st[i]);
				used[i] = 1;
				count.insert(res);
				build_mult(st);
				used[i] = 0;
				res.pop_back();
			}	
		}
	}
	int numTilePossibilities(std::string tiles) {
		build_mult(tiles);
		return count.size();
	}
};

int main() {
	Solution ans;
	std::string ss = "AAB";
	ans.numTilePossibilities(ss);
}