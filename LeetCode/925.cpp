#include <bits/stdc++.h>


class Solution {
public:
	bool isLongPressedName(std::string name, std::string typed) {
		int i = 0;
		int j = 0;
		while(i < name.size() && j < typed.size()) {
			char is = name[i];
			int is_c = 1;
			while(i + 1 < name.size() && name[i] == name[i+1]) {
				is_c++;
				i++;
			}
			char js = typed[j];
			int js_c = 1;
			while(j + 1 < typed.size() && typed[j] == typed[j +1]) {
				js_c++;
				j++;
			}
			if(is != js || is_c > js_c)
				return false;
			i++;
			j++;
		}
		if(j != typed.size() || i != name.size())
			return false;
		return true;
	}
};

int main() {
	Solution asn;
	asn.isLongPressedName("saeed", "ssaaedd");
}