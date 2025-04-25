#include <bits/stdc++.h>

class Solution {
public:
   int maxCount(int m, int n, std::vector<std::vector<int>>& ops) {
		if(ops.empty()) {
			return m * n;
		}
		int minX = INT32_MAX;
		int minY = INT32_MAX;
		for (int i = 0; i < ops.size(); i++)
		{
			minX = std::min(minX, ops[i][0]);
			minY = std::min(minY, ops[i][1]);
		}
		return minX * minY;
	}
};

/*
First of all, consider the base case. If no element is present in ops array, directly return m x n since all elements are maximum (equal to zero).
Now let's say we have n number of operations in the ops array. In each operation, we are given 2 integers a & b and we have to select a sub-matrix of dimension a x b and increment each element in it by 1. If we have 3 operations [2,2], [3,3] & [2,3], and [3,4], the elements in the submatrix [2,2] get incremented in all the 4 operations. So the elements in that sub-matrix will be maximum which is equal to 2 x 2=4 elements.
Did you understand the pattern of increment? No matter how many elements we increase, the sub-matrix with the smallest dimensions will always have the max elements.
So the problem just reduces to finding out the sub-matrix with the smallest dimensions. For that, we require the minimum element from both the first and second fields of the ops array. Let's take an example:
If we have an ops array like this - [[1,3],[4,2],[2,3],[3,3],[2,2]] , the minimum element from the 1st field is 1 (min(1,4,2,3,2)) and from the 2nd field is also 2 (min(3,2,3,3,2)). So the answer is 1 x 2=2.
*/