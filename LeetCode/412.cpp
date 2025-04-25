#include <bits/stdc++.h>



class Solution {
public:
	std::vector<std::string> fizzBuzz(int n) {
		std::vector<std::string> res(n);
		for (int i = 0; i < n; i++)
		{
			if((i + 1) % 3 == 0 && (i + 1) % 5 == 0) {
				res[i] = "FizzBuzz";
			} else if((i + 1) % 3 == 0) {
				res[i] = "Fizz";
			} else if((i + 1) % 5 == 0) {
				res[i] = "Buzz";
			} else {
				res[i] = std::to_string(i + 1);
			}
		}
		return res;
	}
};