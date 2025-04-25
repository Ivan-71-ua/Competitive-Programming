//https://ravesli.com/urok-210-potokovye-klassy-i-stroki/
#include <bits/stdc++.h>

class Solution {
public:
	int countSegments(std::string s) {
		std::stringstream buff;
		buff.str(s);
		int res = 0;
		std::string tmp;
		while (buff >> tmp)
		{
			res++;
		}
		return res;
	}
};

int main() {
	Solution ans;
	ans.countSegments("a");
}