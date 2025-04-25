#include <bits/stdc++.h>
using namespace std;

class Car
{
private:
	static int id;
	int nomer;
	string marka;
	string driver;
	int yourserf_id;

public:
	Car(int nom, string mar, string driv) {
		this->nomer = nom;
		this->marka = mar;
		this->driver = driv;
		this->yourserf_id = id;
		id++;
	}
	int Get_id() {
		return yourserf_id;
	}
};
int Car::id = 0;
int main()
{
	Car Mers(4546, "audi", "Ivan");
	Car Logan(3434, "morel", "Maks");
	cout << Mers.Get_id() << endl;
	cout << Logan.Get_id() << endl;
}