#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> numbers;
	for (int i = 1; i <= 74; i++) {
		numbers.push_back(i);
	}

	for (int i = 1; i <= n; i++) {
		vector<int> representation;

		int remaining = i; 
		for (int num : numbers) {
			if (remaining == 0) break;
			if (num <= remaining) {
					representation.push_back(num);
					remaining -= num;
			}
		}

		cout << representation.size() << " ";
		for (int num : representation) {
			cout << num << " ";
		}
		cout << endl;
	}

	return 0;
}
