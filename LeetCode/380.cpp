#include <bits/stdc++.h>
#include <cstdlib> 


class RandomizedSet {
	std::unordered_map<int, bool> numbs;

public:
   bool insert(int val) {
      if(numbs.count(val))
			return false;
		numbs[val] = true;
		return true;
	}
   bool remove(int val) {
      if(numbs.count(val)) {
			numbs.erase(val);
			return true;
		}
		return false;
   }
   int getRandom() {
      //srand(time(0));
		return std::next(numbs.begin(), rand() % numbs.size())->first;
	}
};