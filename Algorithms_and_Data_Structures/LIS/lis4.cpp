#include <bits/stdc++.h>


int first_less(std::vector<int>& list, int target) {
	int res = -1;
	int r = (int)list.size() - 1;
	int l = 0;
	while (l <= r) {
		int mid = l + (r - l) / 2;

		if (list[mid] < target) {
			res = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	return res;
}

int get_max_lis_stricly(std::vector<int>& list) {
	int n = list.size();
	std::vector<int> max_seq;
	max_seq.push_back(list[0]);
	for (int i = 1; i < n; i++) {
		int idx = first_less(max_seq, list[i]);
		if (idx + 1 < max_seq.size()) {
			max_seq[idx + 1] = list[i];
		} else {
			max_seq.push_back(list[i]);
		}
	}
	return max_seq.size();
}

int first_less_or_equal(std::vector<int>& list, int target) {
	int res = -1;
	int r = (int)list.size() - 1;
	int l = 0;
	while (l <= r) {
		int mid = l + (r - l) / 2;

		if (list[mid] <= target) {
			res = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	return res;
}

int get_max_lis_not_stricly(std::vector<int>& list) {
	int n = list.size();
	std::vector<int> max_seq;
	max_seq.push_back(list[0]);
	for (int i = 1; i < n; i++) {
		int idx = first_less_or_equal(max_seq, list[i]);
		
		if (idx + 1 < max_seq.size()) {
			max_seq[idx + 1] = list[i];
		} else {
			max_seq.push_back(list[i]);
		}
	}
	return max_seq.size();
}

std::vector<int> get_lis_sequence(std::vector<int> list, bool is_strict = true) {
	int n = list.size();
	if (n == 0) return {};

	std::vector<int> max_seq;
	std::vector<int> parent(n, -1);
	std::vector<int> end_max_pos;

	max_seq.push_back(list[0]);
	end_max_pos.push_back(0);

	for (int i = 1; i < n; i++) {
		int idx;
		if (is_strict) {
			idx = first_less(max_seq, list[i]);
		} else {
			idx = first_less_or_equal(max_seq, list[i]);
		}
		
		if (idx + 1 < max_seq.size()) {
			max_seq[idx + 1] = list[i];
			end_max_pos[idx + 1] = i;
			if (idx >= 0) {
				parent[i] = end_max_pos[idx];
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
	for (int i = m - 1; i >= 0; i--) {
		res[i] = list[k];
		k = parent[k];
	}

	return res;
}