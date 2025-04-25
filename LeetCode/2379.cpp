
#include <bits/stdc++.h>



class Solution {
public:
	int minimumRecolors(std::string blocks, int k) {
		int i = 0, j = 0;
		int tmp = 0;
		while(j < k) {
			if(blocks[j] == 'W')
				tmp++;
				j++;
		}
		int res = tmp;
		while(j < blocks.size()) {
			if(blocks[i] == 'W')
				tmp--;
			if(blocks[j] == 'W')
				tmp++;
			res = std::min(res, tmp);
			j++;
			i++;
		}
		return res;
	}
};
int main() {
	Solution ans;
	ans.minimumRecolors("WBBWWBBWBW", 7);
}

