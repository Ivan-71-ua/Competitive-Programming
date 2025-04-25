#include <bits/stdc++.h>


using namespace std;

bool canDivide(const vector<int>& speeds, int n, int k, int limit) {
	int pairs = 0;
	vector<bool> used(speeds.size(), false);

	for (int i = 0; i < 2 * n * k - 1; i++) {
		if (used[i]) continue;
		for (int j = i + 1; j < 2 * n * k; j++) {
			if (!used[j] && speeds[j] - speeds[i] <= limit) {
					used[i] = used[j] = true;
					pairs++;
					break;
			}
		}
		if (pairs >= n) return true;
	}

	return false;
}

int main() {
	int n, k;
	cin >> n >> k;
	
	int total_horses = 2 * n * k;
	vector<int> speeds(total_horses);
	
	for (int i = 0; i < total_horses; i++) {
		cin >> speeds[i];
	}
	
	sort(speeds.begin(), speeds.end());
	
	int low = 0, high = speeds[total_horses - 1] - speeds[0];
	while (low < high) {
		int mid = (low + high) / 2;
		if (canDivide(speeds, n, k, mid)) {
			high = mid;
		} else {
			low = mid + 1;
		}
	}
	
	cout << low << endl;
	
	return 0;
}
