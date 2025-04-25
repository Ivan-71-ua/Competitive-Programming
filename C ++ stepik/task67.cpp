#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
	int p, temp_x, temp_y, temp_x1, temp_y2;
	vector<int> vec;

	while (cin >> p) {
      vec.push_back(p);
   }
	
	bool ansver = false;
	for (int i = 0; i < vec.size(); i += 2) {
		temp_x = vec[i];
		temp_y = vec[i + 1];
		for (int j = i + 2; j < vec.size(); j += 2) {
			temp_x1 = vec[j];
			temp_y2 = vec[j + 1];
			if (temp_x1 == temp_x || temp_y2 == temp_y) {
				ansver = true;
				break;
				
			}
			else if (temp_x - temp_x1 == temp_y - temp_y2 || temp_y - temp_y2 == -(temp_x - temp_x1) ) {
				ansver = true;
				break;
			}
		}
	}
	if (ansver) {
		cout << "YES";
	}
	else  {
		cout << "NO";
	}
}
