#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

bool isDeputyHappyNumber(const string& num) {
	int changes = 0;
	for (size_t i = 1; i < num.size(); ++i) {
		if (num[i] != num[i - 1]) {
			++changes;
		}
	}
	return changes % 2 == 1;
}

int main() {
	int n;
	cin >> n;

	queue<string> q;
	q.push("4");
	q.push("7");

	vector<string> happyDeputyNumbers;
	
	while (happyDeputyNumbers.size() < n) {
		string current = q.front();
		q.pop();
		
		if (isDeputyHappyNumber(current)) {
			happyDeputyNumbers.push_back(current);
		}
		
		q.push(current + "4");
		q.push(current + "7");
	}

	cout << happyDeputyNumbers[n - 1] << endl;
	
	return 0;
}
