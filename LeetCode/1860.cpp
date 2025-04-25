#include <bits/stdc++.h>


class Solution {
public:
	std::vector<int> memLeak(int memory1, int memory2) {
		int time = 1;
		int need = 1;
		while(std::max(memory1, memory2) >= need) {
			if(memory1 >= memory2) {
				memory1 -= need;
			} else {
				memory2 -= need;
			}
			need++;
			time++;
		}
		return {time, memory1, memory2};
	}
};

