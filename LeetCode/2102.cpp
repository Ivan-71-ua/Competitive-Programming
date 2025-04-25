#include <bits/stdc++.h>



class SORTracker {
	std::set<std::pair<int, std::string>> q;
	std::set<std::pair<int, std::string>>::iterator it = q.end();
public:
	SORTracker() {
	}
	void add(std::string name, int score) {
		auto can = q.insert({-score, name}).first;
		if(it == q.end() || *can < *it) {
			it--;
		}
	}
	std::string get() {
		return (it++)->second;
	}
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */