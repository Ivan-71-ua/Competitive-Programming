#include <bits/stdc++.h>
using namespace std;
class A {
public:
	A() {
		cout << "Add dinamic data A";
	}
	virtual ~A() {
		cout << "Delete dinamic data A";
	}
};

class B : public A {
public:
	B() {
		cout << "Add dinamic data B";
	}
	~B() override {
		cout << "Delete dinamic data B";
	}
};

int main() {
	A *val = new B;
   delete val;
   return 0;
}