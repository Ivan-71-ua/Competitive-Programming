#include <bits/stdc++.h>
using namespace std;

class Weapon {
public:
	virtual void Shoot() = 0;
	void Foo() {
		cout << "Foo()";
	}
};
class Gun : public Weapon {
public:
	void Shoot() override {
		cout << "BANG";
	}
};
class Submashine : public Weapon {
public:
	void Shoot() override {
		cout << "BANG BANG BANG";
	}
};
class Knife : public Weapon {
public:
	void Shoot() override {
		cout  << "VCHUH";
	}
};
class Player {
public:
	void Use_weapon(Weapon *wep) {
		wep->Shoot();
	}
};

int main() {
	Knife f;
	Submashine s;
	Player Ivan;
	Ivan.Use_weapon(&s);
}