#include <bits/stdc++.h>
using namespace std;


class A {
public:
	A() {
		mass =  "constr\n";
	}
	A(string st) {
		this->mass = st;
	}
	void Print_Mass() {
		cout << mass;
	}
	private:
	string mass;
};

class B : public A {
public:
	B(string ass) : A(ass) {

	}
};

int main() {

	B was("Ivan");
	was.Print_Mass();
}