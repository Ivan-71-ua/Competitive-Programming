#include <bits/stdc++.h>


class Solution {
public:
	std::string addBinary(std::string a, std::string b) {
		if(a.size() < b.size()) {
			std::swap(a, b);
		}
		int n = b.size();
		b += '0';
		int k = 0;
		int j = n - 1;
		for (int i = a.size() - 1; i >= 0; i--)
		{
			int tp;
			if(j >= 0)
				tp = j;
			else
				tp = n;
			if(i == 0) {
				if(a[i] == '1') {
					if(b[tp] == '1') {
						if(k == 1) {
							a.insert(0, "1");
						} else {
							a[i] = '0';
							a.insert(0, "1");
						}
					} else {
						if(k == 1) {
							a[i] = '0';
							a.insert(0, "1");
						}
					}
				} else {
					if(b[tp] == '1') {
						if(k == 1) {
							a[i] = '0';
							a.insert(0, "1");
						} else {
							a[i] = '1';
						}
					} else {
						if(k == 1) {
							a[i] = '1';
						}
					}
				}
			} else {
				if(a[i] == '0') {
					if (b[tp] == '1') {
						if(k == 1){
							a[i] = '0';
							k = 1;
						} else {
							a[i] = '1';
						}
					} else {
						if(k == 1) {
							a[i] = '1';
							k = 0;
						} else {
							a[i] = '0';
						}
					}
				} else {
					if (b[tp] == '1') {
						if(k == 1) {
							a[i] = '1';
							k = 1;
						} else {
							a[i] = '0';
							k = 1;
						}
					} else {
						if(k == 1) {
							a[i] = '0';
							k = 1;
						} else {
							a[i] = '1';
						}
					}
				}
				j--;
			}
		}
		return a;
	}
};

int main(){
	Solution ams;
	ams.addBinary("110010", "10111");
}