
#include <bits/stdc++.h>

class Solution {
public:
	int compareVersion(std::string version1, std::string version2) {
		for (auto &ch: version1)
		{
			if(ch == '.')
				ch = ' ';
		}
		for (auto &ch: version2)
		{
			if(ch == '.')
				ch = ' ';
		}
		long long ver1 = 0;
		long long ver2 = 0;
		long long tmp1, tmp2;
		std::stringstream parse1(version1);
		std::stringstream parse2(version2);
		while(true) {
			if(parse1 >> tmp1) {
				ver1 += tmp1;
			} else {
				break;
			}
			if(parse2 >> tmp2) {
				ver2 += tmp2;
			} else {
				break;
			}
			if(ver1 < ver2) {
				return -1;
			} else if(ver1 > ver2) {
				return 1;
			} 
		}
		while(parse1 >> tmp1) {
			ver1 += tmp1;
		}
		while(parse2 >> tmp2) {
			ver2 += tmp2;
		}
		if(ver1 < ver2) {
			return -1;
		} else if(ver1 > ver2) {
			return 1;
		} else {
			return 0;
		}
		//while(parse1 >> tmp1)
			//ver1 += tmp1;
		//while(parse2 >> tmp2)
			//ver2 += tmp2;
	}
};