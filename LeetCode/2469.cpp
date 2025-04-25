#include <bits/stdc++.h>


class Solution {
public:
	std::vector<double> convertTemperature(double celsius) {
		double kel = celsius + 273.15;
		double far = celsius * 1.8 + 32.0;
		return {kel, far};
	}
};

