#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define int long long

int get_sum(int a, int b, int* pref_sum) {
	return pref_sum[b] - pref_sum[a - 1];
}

void solve(int L, int R, int* nums, int* pref_sum, int &ans) {
	if (R <= L) {
		ans++;
		return;
	}
	int mid = (L + R) / 2;
	int pref_r = mid + 1;
	int mx_l = mid;
	std::map<int, int> sum_on_sub_l;
	for (int l = mid; l >= L; l--) {
		if (nums[mx_l] < nums[l]) {
			mx_l = l;
		}
		while (pref_r <= R && nums[mx_l] > nums[pref_r]) {
			sum_on_sub_l[get_sum(mid + 2, pref_r + 1, pref_sum)]++;
			pref_r++;
		}
		if (sum_on_sub_l.count(get_sum(l + 1, mx_l + 1, pref_sum) - get_sum(mx_l + 1, mid + 1, pref_sum)))
			ans += sum_on_sub_l[get_sum(l + 1, mx_l + 1, pref_sum) - get_sum(mx_l + 1, mid + 1, pref_sum)];
	}
	int pref_l = mid;
	int mx_r = mid;
	std::map<int, int> sum_on_sub_r;
	for (int r = mid + 1; r <= R; r++) {
		if (nums[mx_r] < nums[r]) {
			mx_r = r;
		}
		while (pref_l >= L && nums[mx_r] > nums[pref_l]) {
			sum_on_sub_r[get_sum(pref_l + 1, mid + 1, pref_sum)]++;
			pref_l--;
		}
		if (sum_on_sub_r.count(get_sum(mx_r + 1, r + 1, pref_sum) - get_sum(mid + 2, mx_r + 1, pref_sum)))
			ans += sum_on_sub_r[get_sum(mx_r + 1, r + 1, pref_sum) - get_sum(mid + 2, mx_r + 1, pref_sum)];
	}
	solve(L, mid, nums, pref_sum, ans);
	solve(mid + 1, R, nums, pref_sum, ans);
}

int32_t main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int n;
	std::cin >> n;
	while (n--) {
		int size;
		std::cin >> size;
		int nums[size];
		for (int i = 0; i < size; i++) {
			std::cin >> nums[i];
		}
		int pref_sum[size + 1];
		pref_sum[0] = 0;
		for (int i = 1; i <= size; i++) {
			pref_sum[i] = pref_sum[i - 1] + nums[i - 1];
		}
		int res = 0;
		solve(0, size - 1, nums, pref_sum, res);
		std::cout << res << '\n';
	}

}
