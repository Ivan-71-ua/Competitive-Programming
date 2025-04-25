#include <bits/stdc++.h>




class Solution {
public:
	int numberOfChild(int n, int k) {
		int currentPosition = 0;
		int direction = 1; 
		for (int i = 0; i < k; ++i) {
			currentPosition += direction;
			if (currentPosition == n - 1 || currentPosition == 0) {
				direction *= -1; 
			}
		}
		return currentPosition;
	}
};

int main() {
	Solution ans;
	ans.numberOfChild(3,5);
}