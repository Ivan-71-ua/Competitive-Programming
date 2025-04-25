#include <bits/stdc++.h>
using namespace std;

class Human {
private:
	string name;
	int age;
	int weight;
public:
	Human(string Name) {
		this->name = Name;
		this->age = 0;
		this->weight = 0;
	}
	Human(string Name, int Age) : Human(Name) {
		this->age = Age;
	}
	Human(string Name, int Age, int Weight) : Human(Name, Age) {
		this->weight = Weight;
	}
};

int main() {
	Human("ivan", 34, 57);
}