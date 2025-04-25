#include <bits/stdc++.h>

class Foo {
	int state = 0;
	std::condition_variable cv;
	std::mutex mt;

public:
	Foo() {
	}

	void first(std::function<void()> printFirst) {
		std::unique_lock<std::mutex> lock(mt);
		// printFirst() outputs "first". Do not change or remove this line.
		while(state != 0) {
			cv.wait(lock);
		}

		printFirst();
		state = 1;
		cv.notify_all();
	}

	void second(std::function<void()> printSecond) {
		std::unique_lock<std::mutex> lock(mt);
		// printSecond() outputs "second". Do not change or remove this line.
		while(state != 1) {
			cv.wait(lock);
		}

		printSecond();
		state = 2;
		cv.notify_all();
	}

	void third(std::function<void()> printThird) {
		std::unique_lock<std::mutex> lock(mt);
		// printThird() outputs "third". Do not change or remove this line.
		while(state != 2) {
			cv.wait(lock);
		}

		printThird();
	}
};