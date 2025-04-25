#include <bits/stdc++.h>
#define ll long long

template <typename T0, typename T1>
class Special {
public:
	Special(T0 val, T1 val1) {
		this->val1 = val;
		this->val2 = val1;
	}
	void Set_size_of() {
		std::cout << sizeof(val1) << std::endl;
		std::cout << sizeof(val2) << std::endl;
	}
private:
	T0 val1;
	T1 val2;
};

class Point{
public:
	Point() {
		z = y = x = 0;
	}
	Point(int a, int b, int c) {
		this->x = a;
		this->y = b;
		this->z = c;
	}
private:
	int x, y, z;
};

int main() {
	int a = 99;
	Point p(1, 1, 1);
	Special <int, Point> sp(a, p);
	sp.Set_size_of();
}