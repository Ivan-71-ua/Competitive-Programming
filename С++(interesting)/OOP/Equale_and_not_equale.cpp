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
	bool operator ==(const Point &other) {
		return this->x == other.x && this->y == other.y && this->z == other.z;
	}
	bool operator !=(const Point &other) {
		return !(this->x == other.x && this->y == other.y && this->z == other.z);
	}
private:
	int t = 4;
	void Print_t() {
		cout << "Sector: " << t;
	}
};

int main() {
	Point A(1, 1, 1);
	Point B(1, 1, 1);
	Point C(0, 0, 0);
	bool result = A != B;
	cout << result << endl;
}