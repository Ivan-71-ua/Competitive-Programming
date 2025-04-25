#include <bits/stdc++.h>
using namespace std;

class Human {
	private:
		string name;
	public:
	string GetName() {
		return name;
	}
	void SetName(string NM) {
		this->name = NM;
	}
};
class Teacher : public Human {
	private :
		string subject;
};
class Student: public Human{
	private:
		string group;
	public:
	void Study() {
		cout << "I am study";
	}
};
class ExtramularStudent: public Student {
	public:
	void Study() {
		cout << "I am study rarely";
	}
};
int main() {
	Student St;
	ExtramularStudent Is;
	St.Study();
	cout << endl;
	Is.Study();
}