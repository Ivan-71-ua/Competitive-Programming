
#include <bits/stdc++.h>



class NumberContainers {
	std::unordered_map<int, std::set<int>> val_min_idx;
	std::unordered_map<int, int> idx_val;
public:
	NumberContainers() {
	}
	
	void change(int index, int number) {
		if(idx_val[index] != 0) {
			val_min_idx[idx_val[index]].erase(index);
		}
		idx_val[index] = number;
		val_min_idx[number].insert(index);
	}
	
	int find(int number) {
		if(val_min_idx[number].empty())
			return -1;
		return *val_min_idx[number].begin();
	}
};
/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers obj = new NumberContainers();
 * obj.change(index,number);
 * int param_2 = obj.find(number);
 */