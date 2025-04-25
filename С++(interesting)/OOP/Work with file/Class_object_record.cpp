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
	void Print() {
		cout << this->x << " " << this->y << " " << this->z;
	}
private:
	int x;
	int y;
	int z;
};

int main() {
	Point p(34, 77, 89);
	Point k(100, 200, 300);
	string name_f = "Class.txt";
	ofstream fout;
	fout.open(name_f, ofstream::app);
	if(!fout.is_open()) {
		cout << "Something wrong";
	}
	else {
		fout.write((char *)&p, sizeof(Point));
		fout.write((char *)&k, sizeof(Point));
	}
	fout.close();
	ifstream fout1;
	fout1.open(name_f);
	if(!fout1.is_open()) {
		cout << "Something wrong";
	}
	else {
		Point f;
		while(fout1.read((char*)&f, sizeof(Point))) {
			f.Print();
			cout << endl;
		}
	}
}