#include <bits/stdc++.h>


class Solution {
public:
	int wateringPlants(std::vector<int>& plants, int capacity) {
		int cap = capacity, c = 0;
		for(int i=0;i<plants.size();i++){
			if(plants[i]>cap){
				c += 2*i;
				cap = capacity;
			}
			c++;
			cap -= plants[i];
		}
		return c;
	}
};