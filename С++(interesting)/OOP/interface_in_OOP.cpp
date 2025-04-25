#include <bits/stdc++.h>
using namespace std;

class IBicycle {
public:
	virtual void RideOn() = 0;
	virtual void TurnOn() = 0;
};

class SimpleBicycle : public IBicycle{
public:
	void RideOn() override {
		cout << "method ride of Simple Bicycle";
	}
	void TurnOn() override {
		cout << "method turn of Simple Bicyle";
	}
};

class SportBicycle: public IBicycle
{
public:
	void RideOn() override {
		cout << "method ride of Sport Bicycle";
	}
	void TurnOn() override {
		cout << "method turn of Sport Bicyle";
	}
};

class Human {
public:
	void Ride_on_Bicycle(IBicycle &val) {
		cout << "ride" << endl;
		val.RideOn();
		cout << endl;
		cout << "turn" << endl;
		val.TurnOn();
		cout << endl;
	}
};

int main() {
	Human Ivan;
	SportBicycle Ir;
	Ivan.Ride_on_Bicycle(Ir);
}