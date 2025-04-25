#include <bits/stdc++.h>


class Solution {
public:
	std::string complexNumberMultiply(std::string num1, std::string num2) {
		std::string tmp;
		num1 += num2;
		for (int i = 0; i < num1.size(); i++)
		{
			if(num1[i] == '+' || num1[i] == 'i') {
				tmp += ' ' + num1[i] + ' ';
			} else {
				tmp += num1[i];
			}
		}
		std::stringstream parse(tmp);
		int a, b, c, d;
		char ch;
		parse >> a >> ch >> b >> ch;
		parse >> c >> ch >> d >> ch;
		int a1 = 1, b1 = 1, c1 = 1, d1 = 0;
		a1 = a * c;
		b1 = a * d;
		c1 = b * c;
		d1 = b * d;
		int real = a1 - d1;
		int image = b1 + c1;
		return std::to_string(real) + '+' + std::to_string(image) + 'i';
	}
};