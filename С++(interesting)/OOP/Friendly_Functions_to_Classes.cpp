#include <bits/stdc++.h>
using namespace std;




class Point
{
private:
	int x;
	int y;
	int z;
public:
	Point(int val_x, int val_y, int val_z) {
		x = val_x;
		y = val_y;
		z = val_z;
	}
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
	friend void ChangeX(Point &val);
};

void ChangeX(Point &val) {
	val.x = -1;
	val.y = -2;
	val.z = -3;
}


int main() {
	Point A(100, 400, 600);
	A.Print();
	ChangeX(A);
	A.Print();
}