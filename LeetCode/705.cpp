#include <bits/stdc++.h>

class MyHashSet {
private:
	std::vector<int> val;
public:
   void add(int key) {
		if(std::find(val.begin(), val.end(), key) == val.end())  {
			val.push_back(key);
		}
	}
   
   void remove(int key) {
		auto it = std::find(val.begin(), val.end(), key);
		if (it != val.end()) {
         val.erase(it);
      }
	}
   
   bool contains(int key) {
		return std::find(val.begin(), val.end(), key) != val.end();
	}
};