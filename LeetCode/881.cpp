#include <bits/stdc++.h>

class Solution {
public:
	int numRescueBoats(std::vector<int>& people, int limit) {
		std::sort(people.begin(), people.end());
		if(people[0] >= limit) {
			return people.size();
		}
		int res = 0;
		int l = 0, r = people.size() - 1;
		while(l <= r) {
			if(r == l) {
				res++;
				l++;
			}
			else {
				if(people[r] == limit) {
					res++;
					r--;
				} else {
					if(people[r] + people[l] <= limit) {
						res++;
						r--;
						l++;
					} else {
						res++;
						r--;
					}
				}
			}
		}
		return res;
	}
};

int main() {
Solution ans;
std::vector<int> ss{3, 2, 2, 1};
ans.numRescueBoats(ss, 3);
}