#include <bits/stdc++.h>
using namespace std;


class Human
{
private:
	int age;
	int weight;
	string name;
public:
	void Print() {
		cout << "Name: " << age << endl;
		cout  << "Weight: " << weight << endl;
		cout << "Age: " << name << endl;
	}
	void Set_date( string n, int a, int w){
		name = n;
		age = a;
		weight = w;
	}
};
class Point
{
private:
	int x;
	int y;
	int z;
public:
	void Print(){
		cout << "A(" << x << "," << y << "," << z << ")";
		cout << endl;
		Print_t();
	}
	void Set_X(int val_x) {
		x = val_x;
	}
	void Set_Y(int val_y) {
		y = val_y;
	}
	void Set_Z(int val_z) {
		z = val_z;
	}
	int Get_X() {
		return x;
	}
	int Get_Y() {
		return y;
	}
	int Get_Z() {
		return z;
	}
private:
	int t = 4;
	void Print_t() {
		cout << "Sector: " << t;
	}
};

int main() {
	Human first_people;
	first_people.Set_date("Ivan", 12, 50);
	first_people.Print();
	cout << "________________________" << endl;
	Point A;
	A.Set_X(4);
	A.Set_Y(-5);
	A.Set_Z(0);
	int x = A.Get_X(), y = A.Get_Y(), z = A.Get_Z();
	cout << x << ' ' << y << ' ' << z;
}