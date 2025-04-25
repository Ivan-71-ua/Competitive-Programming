#include <bits/stdc++.h>



class Solution {
public:
	int distanceBetweenBusStops(std::vector<int>& distance, int start, int destination) {
		if(start > destination)
			std::swap(start, destination);
		int right = 0, total = 0;
		for (int i = start; i < destination; i++)
		{
			right += distance[i];
		}
		for (int i = 0; i < distance.size(); i++)
		{
			total += distance[i];
		}
		return std::min(right, total - right);
	}
};

int main() {
	Solution ans;
	std::vector<int> ss{7, 10, 1, 12, 11, 14, 5, 0};
	ans.distanceBetweenBusStops(ss, 2, 7);
}