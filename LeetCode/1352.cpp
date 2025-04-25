#include <bits/stdc++.h>


class ProductOfNumbers {
	std::vector<int> prod;
	int cur = 1;
public:
	ProductOfNumbers() {
	}
	void add(int num) {
		if(num == 0) {
			cur = 1;
			prod.clear();
		} else {
			cur *= num;
			prod.push_back(cur);
		}
	}
	int getProduct(int k) {
		if(prod.size() < k)
			return 0;
		if(prod.size() == k)
			return cur;
		return prod.back() / prod[prod.size() - k - 1];
	}
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */