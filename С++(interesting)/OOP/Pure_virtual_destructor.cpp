#include <bits/stdc++.h>
using namespace std;

class A {
public:
	A () {

	}
	virtual ~A() = 0;
};
A::~A() {};
class B : public A {
public:
	B() {

	}
	~B() override {

	}
};

int main() {
	B val;
}