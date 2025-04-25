#include <bits/stdc++.h>

class ParkingSystem {
private:
	std::unordered_map<int, int> parking_plase;
public:
   ParkingSystem(int big, int medium, int small) {
		this->parking_plase[1] = big;
		this->parking_plase[2] = medium;
		this->parking_plase[3] = small;
	}
   
   bool addCar(int carType) {
		if(this->parking_plase.count(carType) && this->parking_plase[carType] > 0) {
			this->parking_plase[carType]--;
			return true;
		}
		return false;
	}
};

int main() {
	ParkingSystem ans(1, 1, 0);
	ans.addCar(1);
	ans.addCar(2);
	ans.addCar(3);
	ans.addCar(1);
}