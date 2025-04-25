
#include <bits/stdc++.h>



class Solution {
	int make_all(int idx, int cur_s, std::vector<int>& nums, int target, std::vector<std::vector<int>>& memo) {
		if (idx == nums.size()) {
			return cur_s == target ? 1 : 0;
		}

		// Якщо вже обчислювали цей стан
		if (memo[idx][cur_s + 1000] != -1) {
			return memo[idx][cur_s + 1000];
		}

		// Обчислюємо результати для додавання та віднімання
		int add = make_all(idx + 1, cur_s + nums[idx], nums, target, memo);
		int subtract = make_all(idx + 1, cur_s - nums[idx], nums, target, memo);

		// Зберігаємо результат у мемо
		return memo[idx][cur_s + 1000] = add + subtract;
	}

public:
	int findTargetSumWays(std::vector<int>& nums, int target) {
		// Ініціалізуємо мемо з розміром [n][2001] для зсуву від -1000 до +1000
		std::vector<std::vector<int>> memo(nums.size(), std::vector<int>(2001, -1));
		return make_all(0, 0, nums, target, memo);
	}
};
