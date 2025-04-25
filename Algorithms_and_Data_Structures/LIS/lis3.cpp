#include <bits/stdc++.h>


int first_less_or_equal(std::vector<int> list, int target) {
	int res = -1;
	int r = list.size() - 1;
	int l = 0;
	while (l <= r) {
		int mid = l + (r - l) / 2;
		
		if (list[mid] <= target) {
			res = mid;  
			l = mid + 1;  
		} else {
			r = mid - 1;  
		}
	}
	return res;
}


int get_max_lis(std::vector<int> list) {
	int n = list.size();
	std::vector<int> max_seq;
	max_seq.push_back(list[0]);
	for (int i = 1; i < n; i++)
	{
		int idx = first_less_or_equal(max_seq, list[i]);
		//can used (idx != max_seq.size() - 1 && list[idx] <= list[i])
		if(idx != max_seq.size() - 1) {
			if(idx < 0)
				idx++;
			max_seq[idx] = list[i];
		} else {
			max_seq.push_back(list[i]);
		}
	}
	return max_seq.size();
}

std::vector<int> get_lis_squance(std::vector<int> list) {
	int n = list.size();
	std::vector<int> max_seq;
	std::vector<int> parent(n, -1);
	std::vector<int> end_max_pos;
	max_seq.push_back(list[0]);
	end_max_pos.push_back(0);
	for (int i = 1; i < n; i++)
	{
		int idx = first_less_or_equal(max_seq, list[i]);
		//can used (idx != max_seq.size() - 1 && list[idx] <= list[i])
		if(idx != max_seq.size() - 1) {
			if(idx < 0)
				idx++;
			max_seq[idx] = list[i];
			end_max_pos[idx] = i;
			if(idx > 0) {
				parent[i] = end_max_pos[idx - 1];
			}
		} else {
			max_seq.push_back(list[i]);
			parent[i] = end_max_pos.back();
			end_max_pos.push_back(i);
		}
	}
	int m = max_seq.size();
	std::vector<int> res(m);
	int k = end_max_pos.back();
	for (int i = m - 1; i > -1; i--)
	{
		res[i] = list[k];
		k = parent[k];
	}
	
	return res;
}

int main() {
	std::vector<int> s{3, 2, 4, 1, 6, 5, 8, 4, 9, 7};
	std::vector<int> st{100, 1, 2, 3, 4, 5, 6, 7, 8};
	std::vector<int> sk{8, 7, 6, 5, 4, 3, 2, 1};
	std::vector<int> ss{3, 5, 6, 1,2,7,9};
	//std::cout << get_max_lis(sk);
	for (auto now : get_lis_squance(s) )
	{
		std::cout << now << ' ';
	}
	
}