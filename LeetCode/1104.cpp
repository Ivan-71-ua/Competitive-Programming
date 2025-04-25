#include <bits/stdc++.h>


class Solution {
public:
	std::vector<int> pathInZigZagTree(int label) {
		std::vector<int> way;
		int level = log2(label);
		while(level > 0) {
			way.insert(way.begin(), label);
			int parent = -1;
			if(label % 2 == 0) {
				parent = label / 2;
			} else {
				parent = (label - 1) / 2;
			}
			int prev_level = level - 1;
			int start_point = 1 << prev_level;
			int idx_of_parent = -1;
			std::vector<int> cur_row(1 << prev_level);
			for (int i = 0; i < cur_row.size(); i++, start_point++)
			{
				if(start_point == parent) {
					idx_of_parent = i;
				}
				cur_row[i] = start_point;
			}
			label = cur_row[cur_row.size() - idx_of_parent - 1];
			level--;
		}
		way.insert(way.begin(), 1);
		return way;
	}
};


int main() {
	Solution ans;
	ans.pathInZigZagTree(14);
}