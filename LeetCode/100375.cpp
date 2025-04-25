#include <bits/stdc++.h>








class Solution {
public:
	std::string losingPlayer(int x, int y) {
		int ys = y / 4;
		if(ys < x) {
			if(ys&1) {
				return "Alice";
			} else {
				return "Bob";
			}
		} else if(x <= ys) {
			if(ys&1) {
				return "Alice";
			} else {
				return "Bob";
			}
		}
		return " ";
	}
};