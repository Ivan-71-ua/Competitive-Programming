#include <bits/stdc++.h>
using namespace std;

class Car {
public:
	void Driver() {
		cout << "I am driving";
	}
};

class Airplane {
public:
	void Fly() {
		cout << "I am flying";
	}
};

class AirCar : public Car, public Airplane {
};


int main()
{
	AirCar pap;
	pap.Driver();
	pap.Fly();
}