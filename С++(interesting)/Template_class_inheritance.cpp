#include <bits/stdc++.h>
#include <typeinfo>
#define ll long long

template <typename T0>
class Special {
public:
	Special(T0 val) {
		this->val1 = val;
	}
	void Set_size_of() {
		std::cout << sizeof(val1) << std::endl;
	}
protected:
	T0 val1;
};


template<typename T0> 
class Type_inf: public Special<T0> {
public:
	Type_inf(T0 value):Special<T0>(value){
		
	}
	void Show_inf() {
		std::cout << typeid(this->val1).name() << std::endl;
	}
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
	double a = 99;
	Point p(1, 1, 1);
	Type_inf<Point> tp(p);
	tp.Set_size_of();
	tp.Show_inf();
}