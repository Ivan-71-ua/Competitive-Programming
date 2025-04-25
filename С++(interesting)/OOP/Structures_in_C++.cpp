#include <bits/stdc++.h>
#define ll long long



class Point{
public:
	Point() {
		z = y = x = 0;
	}
	Point(int a, int b, int c) {
		this->x = a;
		this->y = b;
		this->z = c;
	}
private:
	int x, y, z;
};

struct PointS
{
	PointS() {
		z = y = x = 0;
	}
	PointS(int a, int b, int c) {
		this->x = a;
		this->y = b;
		this->z = c;
	}
private:
	int x, y, z;
};

struct PointS2: PointS
{
	/* data */
};

class Point2 : Point {

};

int main() {
	PointS p(0, 0, 0);
	Point l(1, 1, 1);
}