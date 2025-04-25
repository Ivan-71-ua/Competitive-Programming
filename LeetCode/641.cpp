#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <array>
#include <numeric>
#include <queue>
#include <deque>
#include <cmath>
#include <climits>
#include <string>


const int ZERO = []()
   {
      std::ios_base::sync_with_stdio(false);
      std::cin.tie(nullptr);
      return 0;
   }();

class MyCircularDeque {
	std::vector<int> q;
	int maxs;
	int size;
public:
	MyCircularDeque(int k) {
		maxs = size = k;
	}
	bool insertFront(int value) {
		if (size) {
			q.insert(q.begin(), value);
			size--;
			return true;
		}
		return false;
	}

	bool insertLast(int value) {
		if (size) {
			q.push_back(value);
			size--;
			return true;
		}
		return false;
	}

	bool deleteFront() {
		if (size == maxs) {
			return false;
		}
		size++;
		q.erase(q.begin());
		return true;
	}

	bool deleteLast() {
		if (size == maxs) {
			return false;
		}
		size++;
		q.pop_back();
		return true;
	}

	int getFront() {
		if (size == maxs) return -1;
		return *q.begin();
	}

	int getRear() {
		if (size == maxs) return -1;
		return q.back();
	}

	bool isEmpty() {
		if (size == maxs) return true;
		return false;
	}

	bool isFull() {
		if (size == 0) return true;
		return false;
	}
};