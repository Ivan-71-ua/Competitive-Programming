#include <bits/stdc++.h>
using namespace std;

class Car {
public:
	void Use() {
		cout << "I am driving";
	}
};

class Airplane {
public:
	void Use() {
		cout << "I am flying";
	}
};

class AirCar : public Car, public Airplane {
};


int main()
{
	AirCar pap;
	(Car(pap)).Use();
	cout << endl;
	(Airplane(pap)).Use();
}