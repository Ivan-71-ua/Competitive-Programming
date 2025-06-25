#include <bits/stdc++.h>

class Solution {
	long long countPairsLE(const std::vector<int>& A, const std::vector<int>& B, long long target)
	{
		long long cnt = 0;
		int m = static_cast<int>(B.size());
		for (int a : A) {
			if (a > 0) {                           
				int l = 0, r = m;
				while (l < r) {
					int mid = (l + r) >> 1;
					(1LL * a * B[mid] <= target) ? l = mid + 1 : r = mid;
				}
				cnt += l;
			} else if (a < 0) {                    
				int l = 0, r = m;
				while (l < r) {
					int mid = (l + r) >> 1;
					(1LL * a * B[mid] <= target) ? r = mid : l = mid + 1;
				}
				cnt += m - l;
			} else {                               
				if (target >= 0) cnt += m;
			}
		}
		return cnt;
	}

public:
	long long kthSmallestProduct(std::vector<int>& nums1, std::vector<int>& nums2, long long k)
	{
		long long lo = -1e10, hi = 1e10;
		while (lo < hi) {
			long long mid = lo + (hi - lo) / 2;
			(countPairsLE(nums1, nums2, mid) >= k) ? hi = mid : lo = mid + 1;
		}
		return lo;
	}
};
