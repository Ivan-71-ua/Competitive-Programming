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
	Point() {

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
	Point operator +(const Point &other) {
		Point temp1;
		temp1.x = this->x + other.x;
		temp1.y = this->y + other.y;
		temp1.z = this->z + other.z;
		return temp1;
	}
private:
	int t = 4;
	void Print_t() {
		cout << "Sector: " << t;
	}
};

int main() {
	Point A(0,3,3);
	Point B(2, 0, 0);
	Point C = A + B;
	return 0;
}