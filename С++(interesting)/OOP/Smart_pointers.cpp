#include <bits/stdc++.h>
#define ll long long

template<typename T>
class SmartPointes {
public:
	SmartPointes(T *ptr) {
		this->ptr = ptr;
	}
	~SmartPointes() {
		delete ptr;
	}
	T& operator*() {
		return *ptr;
	}
private: 
	T *ptr;
};

int main() {
	SmartPointes<int> pointer = new int(66565);
	std::cout << *pointer;
}