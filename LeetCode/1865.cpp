

#include <bits/stdc++.h>


class FindSumPairs {
	std::unordered_map<int, int> cnt;
	std::vector<int> save1, save2;
public:
	FindSumPairs(std::vector<int>& nums1, std::vector<int>& nums2) {
		int n = nums1.size(), m = nums2.size();
		save1.resize(n);
		save2.resize(m);
		for (int i = 0; i < n; i++) {
			save1[i] = nums1[i];
		}
		for (int i = 0; i < m; i++) {
			cnt[nums2[i]]++;
			save2[i] = nums2[i];
		}
	}
	
	void add(int index, int val) {
		cnt[save2[index]]--;
		save2[index] += val;
		cnt[save2[index]]++;
	}
	
	int count(int tot) {
		int res = 0;
		for(auto n: save1) {
			int diff = tot - n;
			if(cnt.count(diff)) {
				res += cnt[diff];
			}
		}
		return res;
	}
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */