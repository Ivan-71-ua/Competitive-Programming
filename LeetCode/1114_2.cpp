

#include <bits/stdc++.h>



class Foo {
	std::mutex mt1, mt2;

public:
	Foo() {
		mt1.lock();
		mt2.lock();
	}

	void first(std::function<void()> printFirst) {
		// printFirst() outputs "first". Do not change or remove this line.
		printFirst();
		mt1.unlock();
	}

	void second(std::function<void()> printSecond) {
		mt1.lock();
		// printSecond() outputs "second". Do not change or remove this line.
		printSecond();
		mt2.unlock();
	}

	void third(std::function<void()> printThird) {
		mt2.lock();
		// printThird() outputs "third". Do not change or remove this line.
		printThird();
	}
};