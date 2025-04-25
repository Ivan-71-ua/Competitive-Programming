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
};

int main() {
	Point A(0,3,3);
	A.Print();
	cout << endl;
	A.Set_X(4);
	A.Set_Y(-5);
	A.Set_Z(0);
	int x = A.Get_X(), y = A.Get_Y(), z = A.Get_Z();
	cout << x << ' ' << y << ' ' << z;
}