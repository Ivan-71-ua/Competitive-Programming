#include <bits/stdc++.h>

class Solution {
public:
   int tribonacci(int n) {
		std::vector<int> treebn(n + 3);
		treebn[0] = 0;
		treebn[1] = 1;
		treebn[2] = 1;
		for (int i = 3; i <= n; i++)
		{
			treebn[i] = treebn[i - 1]  + treebn[i - 2] + treebn[i - 3];
		}
		return treebn[n];
	}
};

int main() {
	
}