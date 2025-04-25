#include <bits/stdc++.h>


class Solution {
public:
	std::vector<int> pathInZigZagTree(int label) {
		std::vector<int> r;
		r.push_back(label);
		int d=log2(label),m;
		while(d)
		{
			m=pow(2,d)+pow(2,d+1)-1-label;  //mirror w.r.to non zig zag version 
			// OR you can do pow(2,d-1)+pow(2,d)-1-label/2;
			//4+7-(14/2) == 4+7-7 == 4 
			r.push_back(m/2);
			label=m/2;
			d--;
		}
		reverse(r.begin(),r.end());
		return r;
	}
};