#include <bits/stdc++.h>



class Solution {
public:
int up(std::vector<int>& arr, int st) {
	for (int i = st; i < arr.size(); i++)
	{
		if(i == arr.size() -1 || arr[i] >= arr[i + 1])
			return i;
	}
	return 0;
}
int down(std::vector<int>& arr, int st) {
	for (int i = st; i < arr.size(); i++)
	{
		if(i == arr.size() - 1 || arr[i] <= arr[i + 1])
			return i;
	}
	return 0;
}
	bool validMountainArray(std::vector<int>& arr) {
		if(arr.size() < 3)
			return false;
		bool ch = 1;
		int cnt = 0;
		int st = 0;
		int prev = 0;
		while(st < arr.size() -1) {
			if(ch) {
				int cur_p = up(arr, st);
				if(prev == cur_p)
					return false;
				prev = st;
				st = cur_p;
				ch = 0;
				cnt++;
			} else {
				int cur_p = down(arr, st);
				if(prev == cur_p)
					return false;
				prev = st;
				st = cur_p;
				ch = 1;
				cnt++;
			}
		}
		if(cnt & 1)
			return false;
		return true;
	}
};

int main() {
	Solution asi;
	std::vector<int> ss{0, 3, 2, 1};
	asi.validMountainArray(ss);
}