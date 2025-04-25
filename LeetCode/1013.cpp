
#include <bits/stdc++.h>



class Solution {
public:
	bool canThreePartsEqualSum(std::vector<int>& arr) {
		int sum = 0;
		for (auto now: arr)
		{
			sum += now;
		}
		if(sum % 3 != 0)
			return false;
		sum /= 3;
		int cur_s = 0;
		int i = 0;
		cur_s += arr[i++];
		while(i < arr.size() && cur_s != sum) {
			cur_s += arr[i];
			i++;
		}
		if(sum != cur_s)
			return false;
		if(i >= arr.size())
			return false;
		cur_s = arr[i++];
		while(i < arr.size() && cur_s != sum) {
			cur_s += arr[i];
			i++;
		}
		if(sum != cur_s)
			return false;
		if(i >= arr.size())
			return false;
		cur_s = arr[i++];
		while(i < arr.size() && cur_s != sum) {
			cur_s += arr[i];
			i++;
		}
		if(sum != cur_s && i != arr.size())
			return false;
		return true;
	}
};

int main() {
	Solution ans;
	std::vector<int> ss{0,2,1,-6,6,-7,9,1,2,0,1};
	ans.canThreePartsEqualSum(ss);
}