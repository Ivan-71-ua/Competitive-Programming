#include <bits/stdc++.h>
#include <fstream>
using namespace std;

class Point {
public:
	Point() {
		x = y = z = 0;
	}
	Point(int x, int y ,int z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
private:
	int x;
	int y;
	int z;
	friend ostream &operator<<(ostream &os, const Point &point);
	friend istream &operator>>(istream &is, Point &point);
};

ostream& operator<<(ostream& os, const Point& point) {
	os << point.x << " " << point.y << " " << point.z;
	return os;
};

istream& operator>>(istream& is, Point& point) {
	is >> point.x >> point.y >> point.z;
	return is;
};


int main() {
	Point point(34, 77, 89);
	Point k(100, 200, 300);
	fstream fs;
	fs.open("fsClass.txt", fstream::in | fstream::out | fstream::app);
	if(!fs.is_open()) {
		cout << "somethig wromg";
	}
	else {
		int val;
		cin >> val;
		if (val == 1) {
			fs << point << "\n";
		}
		else if (val == 2) {
			Point l;
			while(fs >> l) {
				cout << l << endl;
			}
		}
	}
	fs.close();
}
