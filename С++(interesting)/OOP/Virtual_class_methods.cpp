#include <bits/stdc++.h>
using namespace std;


class Gun {
public:
	virtual void Shoot() {
		cout << "BANG\n";
	}
};

class SubmachineGun : public Gun{
public:
	void Shoot() override {
		cout << "BANG BANG BANG\n";
	}
};

class Minigan : public Gun{
public:
	void Shoot() override {
		cout << "BAGRAHTT\n";
	}
	
};

class Player{
public:
	void Shoot_Gun(Gun *gun) {
		gun->Shoot();
	}
};

int main() {
	Player Ivan;
	Minigan Min;
	Gun glog;
	SubmachineGun M3000;
	Ivan.Shoot_Gun(&M3000);
}