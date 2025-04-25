#include <bits/stdc++.h>


class Solution {
public:
	std::vector<long long> countKConstraintSubstrings(std::string s, int k, std::vector<std::vector<int>>& queries) {
		int n = s.size();
		std::vector<long long> pref(n);
		std::vector<int> v(n);
		std::vector<long long> ans;
		int ones = 0, zeros = 0;
		int l = 0, r = 0;
		while(r < n) {
			if(s[r] == '0')
				zeros++;
			else
				ones++;	
			while(zeros > k && ones > k) {
				if(s[l] == '0')
					zeros--;
				else
					ones--;
				l++;
			}
			v[r] = l;
			pref[r] = r - l + 1;
			r++;
		}

		for (int i = 1; i < n; i++)
		{
			pref[i] += pref[i - 1];
		}
		for (auto q : queries)
		{
			l = q[0], r = q[1];
			int tmp = q[1] + 1;
			while(l <= r) {
				int mid = (l + r) / 2;
				if(q[0] <= v[mid]) {
					r = mid - 1;
					tmp = mid;
				} else {
					l = mid + 1;
				}
			}
			long long subs_in_range = pref[q[1]];
			if(tmp -1 > 0)
				subs_in_range -= pref[tmp - 1];
			tmp -= q[0];
			subs_in_range += (long long)tmp * (tmp + 1) / 2;
			ans.push_back(subs_in_range);
		}
		return ans;
	}
};