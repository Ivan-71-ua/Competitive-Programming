#include <bits/stdc++.h>


class Solution {
public:
	int garbageCollection(std::vector<std::string>& garbage, std::vector<int>& travel) {
		int idx_p = -1;
		int papers = 0;
		int idx_g = -1;
		int glass = 0;
		int idx_m = -1;
		int metal = 0;
		for (int i = 0; i < garbage.size(); i++)
		{
			int tmp = std::count(garbage[i].begin(), garbage[i].end(), 'G');
			if(tmp) {
				idx_g = i;
				glass += tmp;
			}
			tmp = std::count(garbage[i].begin(), garbage[i].end(), 'P');
			if(tmp) {
				idx_p = i;
				papers += tmp;
			}
			tmp = std::count(garbage[i].begin(), garbage[i].end(), 'M');
			if(tmp) {
				idx_m = i;
				metal += tmp;
			}
		}
		std::vector<int> pref(travel.size());
		pref[0] = travel[0];
		for (int i = 1; i < travel.size(); i++)
		{
			pref[i] = pref[i - 1] + travel[i];
		}
		int res = 0;
		if(idx_g != -1) {
			res += (idx_g - 1 > -1 ? pref[idx_g -1] : 0) + glass;
		}
		if(idx_m != -1) {
			res += (idx_m - 1 > -1 ? pref[idx_m -1] : 0) + metal;
		}
		if(idx_p != -1) {
			res += (idx_p - 1 > -1 ? pref[idx_p -1] : 0) + papers;
		}
		return res;
	}
};


int main() {
	Solution ans;
	std::vector<std::string> ss{"G","P","GP","GG"};
	std::vector<int> kk{2,4,3};
	ans.garbageCollection(ss, kk);
}