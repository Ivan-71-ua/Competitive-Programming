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
		x = 0;
		y = 0;
		z = 0;
	}
	Point(bool as) {
		if(as) {
			x = 1;
			y = 1;
			z = 1;
		}
		else {
			x = -1;
			y = -1;
			z = -1;
		}
	}
	void Print(){
		cout << "A(" << x << "," << y << "," << z << ")";
		cout << endl;
		cout <<"Sector: " <<  t <<  endl;
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
};

int main() {
	Point A;
	A.Print();
	Point B(false);
	B.Print();
	Point C(0, -1, 99);
	C.Print();
}