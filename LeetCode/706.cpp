#include <bits/stdc++.h>

class MyHashMap {
private:
	std::vector<int> keys;
	std::vector<int> vals;

public:
   void put(int key, int value) {
      if(std::find(keys.begin(), keys.end(), key) != keys.end()) {
			int i = 0;
			for (; i < keys.size(); i++)
			{
				if(keys[i] == key) break;
			}
			vals[i] = value;
			} else {
			keys.push_back(key);
			vals.push_back(value);
		}
   }
   
   int get(int key) {
      if(std::find(keys.begin(), keys.end(), key) != keys.end()) {
			int i = 0;
			for (; i < keys.size(); i++)
			{
				if(keys[i] == key) break;
			}
			return vals[i];
			} else {
				return -1;
		}
   }
   
   void remove(int key) {
      if(std::find(keys.begin(), keys.end(), key) != keys.end()) {
			int i = 0;
			for (; i < keys.size(); i++)
			{
				if(keys[i] == key) break;
			}
			auto it = keys.begin(), it2 = vals.begin();
			vals.erase(it2 + i);
			keys.erase(it +i);
		}
	}
};